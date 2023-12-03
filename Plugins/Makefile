CMAKE_BIN ?= cmake
ANDROID_NDK_ROOT ?=
CXXFLAGS += -std=c++17
STRIP ?= strip

BUILD_DIRS = \
	build/windows/x86_64 build/windows/x86 \
	build/linux/x86_64 build/linux/x86 \
	build/macos build/ios build/tvos \
	build/android/arm64 build/android/arm32 build/android/x86 build/android/x86_64

# Misc
$(BUILD_DIRS):
	mkdir -p $@

%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)
.PRECIOUS: %/libyogacore.a

%/flex-ui.dll: LINKFLAGS += -shared "-Wl,--version-script,src~/link-version-script.txt"
%/flex-ui.dll: src~/flex-ui.cpp yoga~/%/libyogacore.a | %
	$(CXX) -o $@ $^ -Iyoga~ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/flex-ui.so: CXXFLAGS += -fPIC
%/flex-ui.so: LINKFLAGS += -shared "-Wl,--version-script,src~/link-version-script.txt"
%/flex-ui.so: src~/flex-ui.cpp yoga~/%/libyogacore.a | %
	$(CXX) -o $@ $^ -Iyoga~ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/flex-ui.dylib: LINKFLAGS += -shared "-Wl,-exported_symbol,*FlexUi_*"
%/flex-ui.dylib: src~/flex-ui.cpp yoga~/%/libyogacore.a | %
	$(CXX) -o $@ $^ -Iyoga~ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

# Windows
yoga~/build/windows/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_COMPILER="$(CXX)"

build/windows/x86_64/flex-ui.dll: CXX = x86_64-w64-mingw32-c++
build/windows/x86_64/flex-ui.dll: STRIP = x86_64-w64-mingw32-strip
build/windows/x86/flex-ui.dll: CXX = i686-w64-mingw32-c++
build/windows/x86/flex-ui.dll: STRIP = i686-w64-mingw32-strip


# Linux
yoga~/build/linux/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_FLAGS="$(CXXFLAGS)"

build/linux/x86/flex-ui.so: CXXFLAGS += -m32


# macOS
yoga~/build/macos/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"

build/macos/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64


# iOS
yoga~/build/ios/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_OSX_ARCHITECTURES="arm64" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_OSX_SYSROOT=iphoneos

build/ios/flex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk iphoneos)


# tvOS
yoga~/build/tvos/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_OSX_ARCHITECTURES="arm64" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_OSX_SYSROOT=appletvos

build/tvos/flex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk appletvos)

# Android
yoga~/build/android/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_COMPILER="$(CXX)"

build/android/%/flex-ui.so: CXXFLAGS += -static-libstdc++
build/android/%/flex-ui.so: STRIP = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/llvm-strip)

build/android/arm64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
build/android/arm32/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi19-clang++)
build/android/x86_64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
build/android/x86/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android19-clang++)


# Targets
windows-x86_64: build/windows/x86_64/flex-ui.dll
windows-x86: build/windows/x86/flex-ui.dll

linux-x86_64: build/linux/x86_64/flex-ui.so
linux-x86: build/linux/x86/flex-ui.so

macos-universal: build/macos/flex-ui.dylib
ios-arm64: build/ios/flex-ui.dylib
tvos-arm64: build/tvos/flex-ui.dylib

android-arm64: build/android/arm64/flex-ui.so
android-arm32: build/android/arm32/flex-ui.so
android-x86_64: build/android/x86_64/flex-ui.so
android-x86: build/android/x86/flex-ui.so
