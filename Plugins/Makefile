STRIP ?= strip
SED ?= sed
# WebGL toolchain
EMAR ?= emar
EMCXX ?= em++
# Android setup
ANDROID_NDK_ROOT ?=
# macOS
CODESIGN ?= codesign
MACOS_CODESIGN_SIGNATURE ?=

LINKFLAGS += -shared
CXXFLAGS += -std=c++20 -fvisibility=hidden
ifeq ($(DEBUG),1)
	CXXFLAGS += -O0 -g
else
	CXXFLAGS += -O2
endif

BUILD_DIRS = \
	build/windows/x86_64 build/windows/x86 \
	build/linux/x86_64 \
	build/macos \
	build/android/arm64 build/android/arm32 build/android/x86 build/android/x86_64 \
	build/webgl

# Misc
$(BUILD_DIRS):
	mkdir -p $@

# Requires `cpp-amalgamate`, install with `cargo install cpp-amalgamate`
# Reference: https://github.com/Felerius/cpp-amalgamate
#
# The sed script prepends an underscore to all Yoga symbols to avoid symbol clashes with
# the version of Yoga embedded within Unity, fixing iOS / tvOS / visionOS / WebGL builds.
flex-ui-amalgamated.cpp: src~/flex-ui.cpp yoga~
	cpp-amalgamate -d yoga~ $< | $(SED) 's/\bYG/_YG/g' > $@

%/flex-ui-amalgamated.o~: flex-ui-amalgamated.cpp | %
	$(CXX) -c -o $@ $< $(CXXFLAGS)
%/libflex-ui.a: %/flex-ui-amalgamated.o~
	$(AR) r $@ $<

%/flex-ui.dll: flex-ui-amalgamated.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.so: CXXFLAGS += -fPIC
%/libflex-ui.so: flex-ui-amalgamated.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.dylib: flex-ui-amalgamated.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	install_name_tool -id @rpath/$(@F) $@
	$(STRIP) -x $@
ifdef MACOS_CODESIGN_SIGNATURE
	[[ "$@" == *"/macos/"* ]] && $(CODESIGN) -s "$(MACOS_CODESIGN_SIGNATURE)" $@ || true
endif

# macOS
build/macos/libflex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64

# Android
check-ndk-root:
ifndef ANDROID_NDK_ROOT
	$(error ANDROID_NDK_ROOT must be set for Android builds!)
endif

build/android/%/libflex-ui.so: CXXFLAGS += -static-libstdc++
build/android/%/libflex-ui.so: STRIP = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/llvm-strip)

build/android/arm64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
build/android/arm64/libflex-ui.so: check-ndk-root
build/android/arm32/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi21-clang++)
build/android/arm32/libflex-ui.so: check-ndk-root
build/android/x86_64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
build/android/x86_64/libflex-ui.so: check-ndk-root
build/android/x86/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android21-clang++)
build/android/x86/libflex-ui.so: check-ndk-root

# WebGL
build/webgl/libflex-ui.a: CXXFLAGS += -fno-exceptions
build/webgl/libflex-ui.a: CXX = $(EMCXX)
build/webgl/libflex-ui.a: AR = $(EMAR)

# Targets
windows-x86_64: build/windows/x86_64/flex-ui.dll
windows-x86: build/windows/x86/flex-ui.dll
all-windows: windows-x86_64 windows-x86

windows-x86_64-mingw: CXX = x86_64-w64-mingw32-c++
windows-x86_64-mingw: STRIP = x86_64-w64-mingw32-strip
windows-x86_64-mingw: LINKFLAGS += -static-libgcc -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
windows-x86_64-mingw: build/windows/x86_64/flex-ui.dll

windows-x86-mingw: CXX = i686-w64-mingw32-c++
windows-x86-mingw: STRIP = i686-w64-mingw32-strip
windows-x86-mingw: LINKFLAGS += -static-libgcc -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
windows-x86-mingw: build/windows/x86/flex-ui.dll
all-windows-mingw: windows-x86_64-mingw windows-x86-mingw

linux-x86_64: build/linux/x86_64/libflex-ui.so
all-linux: linux-x86_64

macos-universal: build/macos/libflex-ui.dylib
all-apple: macos-universal

android-arm64: build/android/arm64/libflex-ui.so
android-arm32: build/android/arm32/libflex-ui.so
android-x86_64: build/android/x86_64/libflex-ui.so
android-x86: build/android/x86/libflex-ui.so
all-android: android-arm64 android-arm32 android-x86_64 android-x86

webgl: build/webgl/libflex-ui.a
all-webgl: webgl

# Dockerized builds
docker-all-linux:
	docker build -f src~/Dockerfile.build.linux --platform=linux/amd64 -t gilzoide-flex-ui-build-linux:latest src~
	docker run --rm -v "$(CURDIR)":/src -w /src --platform=linux/amd64 gilzoide-flex-ui-build-linux:latest make all-linux
docker-all-android:
	docker build -f src~/Dockerfile.build.android --platform=linux/amd64 -t gilzoide-flex-ui-build-android:latest src~
	docker run --rm -v "$(CURDIR)":/src -w /src --platform=linux/amd64 gilzoide-flex-ui-build-android:latest make all-android
docker-all-windows:
	docker build -f src~/Dockerfile.build.windows -t gilzoide-flex-ui-build-windows:latest src~
	docker run --rm -v "$(CURDIR)":/src -w /src gilzoide-flex-ui-build-windows:latest make all-windows-mingw
docker-all-webgl:
	docker build -f src~/Dockerfile.build.webgl --platform=linux/amd64 -t gilzoide-flex-ui-build-webgl:latest src~
	docker run --rm -v "$(CURDIR)":/src -w /src --platform=linux/amd64 gilzoide-flex-ui-build-webgl:latest make all-webgl
