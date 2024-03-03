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
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.so: CXXFLAGS += -fPIC
%/libflex-ui.so: src~/flex-ui.cpp | %
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/libflex-ui.dylib: src~/flex-ui.cpp | %
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
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
build/android/%/libflex-ui.so: CXXFLAGS += -static-libstdc++
build/android/%/libflex-ui.so: STRIP = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/llvm-strip)

build/android/arm64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
build/android/arm32/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi19-clang++)
build/android/x86_64/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
build/android/x86/libflex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android19-clang++)

# WebGL
build/webgl/flex-ui.bc: src~/flex-ui.cpp | build/webgl
# Workaround: prepend Yoga symbols with a '_' to avoid build errors,
# since Unity already exports some of them (used by UI Toolkit).
# C++ -> LLVM IR -> rename functions in text -> LLVM Bitcode
	$(EMCXX) -c $< $(CXXFLAGS) -emit-llvm -S -o - \
		| $(SED) -e 's/@YG/@_YG/' \
		| $(EMCXX) -o $@ -c -emit-llvm -x ir -

# Targets
windows-x86_64: build/windows/x86_64/flex-ui.dll
windows-x86: build/windows/x86/flex-ui.dll

windows-mingw-x86_64: CXX = x86_64-w64-mingw32-c++
windows-mingw-x86_64: STRIP = x86_64-w64-mingw32-strip
windows-mingw-x86_64: LINKFLAGS += -static-libgcc -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
windows-mingw-x86_64: build/windows/x86_64/flex-ui.dll

windows-mingw-x86: CXX = i686-w64-mingw32-c++
windows-mingw-x86: STRIP = i686-w64-mingw32-strip
windows-mingw-x86: LINKFLAGS += -static-libgcc -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
windows-mingw-x86: build/windows/x86/flex-ui.dll

linux-x86_64: build/linux/x86_64/libflex-ui.so

macos-universal: build/macos/libflex-ui.dylib
ios-arm64: build/ios/libflex-ui.dylib
tvos-arm64: build/tvos/libflex-ui.dylib
visionos-arm64: build/visionos/libflex-ui.dylib

android-arm64: build/android/arm64/libflex-ui.so
android-arm32: build/android/arm32/libflex-ui.so
android-x86_64: build/android/x86_64/libflex-ui.so
android-x86: build/android/x86/libflex-ui.so

webgl: build/webgl/flex-ui.bc
