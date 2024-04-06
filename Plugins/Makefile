STRIP ?= strip
EMCXX ?= em++
SED ?= sed
ANDROID_NDK_ROOT ?=

LINKFLAGS += -shared
CXXFLAGS += -Iyoga~ -std=c++20 -fvisibility=hidden
ifeq ($(DEBUG),1)
	CXXFLAGS += -O0 -g
else
	CXXFLAGS += -O2
endif

BUILD_DIRS = \
	build/windows/x86_64 build/windows/x86 \
	build/linux/x86_64 \
	build/macos build/ios build/tvos build/visionos \
	build/android/arm64 build/android/arm32 build/android/x86 build/android/x86_64 \
	build/webgl

# Misc
$(BUILD_DIRS):
	mkdir -p $@

%/flex-ui.dll: src~/flex-ui.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.so: CXXFLAGS += -fPIC
%/libflex-ui.so: src~/flex-ui.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.dylib: src~/flex-ui.cpp | %
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

# macOS
build/macos/libflex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64

# iOS
build/ios/libflex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk iphoneos)

# tvOS
build/tvos/libflex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk appletvos)

# visionOS
build/visionos/libflex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk xros)

# Android
check-ndk-root:
ifndef ANDROID_NDK_ROOT
	$(error ANDROID_NDK_ROOT must be set for Android builds!)
endif

build/android/%/libflex-ui.so: CXXFLAGS += -static-libstdc++
build/android/%/libflex-ui.so: STRIP = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/llvm-strip)

build/android/arm64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
build/android/arm64/libflex-ui.so: check-ndk-root
build/android/arm32/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi19-clang++)
build/android/arm32/libflex-ui.so: check-ndk-root
build/android/x86_64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
build/android/x86_64/libflex-ui.so: check-ndk-root
build/android/x86/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android19-clang++)
build/android/x86/libflex-ui.so: check-ndk-root

# WebGL
build/webgl/libflex-ui.bc: src~/flex-ui.cpp | build/webgl
# Workaround: prepend Yoga symbols with a '_' to avoid build errors,
# since Unity already exports some of them (used by UI Toolkit).
# C++ -> LLVM IR -> rename functions in text -> LLVM Bitcode
	$(EMCXX) -c $< $(CXXFLAGS) -emit-llvm -S -o - \
		| $(SED) -e 's/@YG/@_YG/' \
		| $(EMCXX) -o $@ -c -emit-llvm -x ir -

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
ios-arm64: build/ios/libflex-ui.dylib
tvos-arm64: build/tvos/libflex-ui.dylib
visionos-arm64: build/visionos/libflex-ui.dylib
all-apple: macos-universal ios-arm64 tvos-arm64 visionos-arm64

android-arm64: build/android/arm64/libflex-ui.so
android-arm32: build/android/arm32/libflex-ui.so
android-x86_64: build/android/x86_64/libflex-ui.so
android-x86: build/android/x86/libflex-ui.so
all-android: android-arm64 android-arm32 android-x86_64 android-x86

webgl: build/webgl/libflex-ui.bc
all-webgl: webgl

# Dockerized builds
docker-all-linux:
	docker build -f src~/Dockerfile.build.linux -t gilzoide-flex-ui-build-linux:latest .
	docker run --rm -v "$(CURDIR)":/src -w /src --platform=linux/amd64 gilzoide-flex-ui-build-linux:latest make all-linux
docker-all-windows:
	docker build -f src~/Dockerfile.build.windows -t gilzoide-flex-ui-build-windows:latest src~
	docker run --rm -v "$(CURDIR)":/src -w /src gilzoide-flex-ui-build-windows:latest make all-windows-mingw
