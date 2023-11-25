CMAKE_BIN ?= cmake
ANDROID_NDK_ROOT ?=

BUILD_DIRS = \
	windows/x86_64 windows/x86 \
	linux/x86_64 linux/x86 \
	osx ios \
	android/arm64 android/arm32 android/x86 android/x86_64

# Misc
$(BUILD_DIRS):
	mkdir -p $@


# Windows
yoga~/build/windows/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_FLAGS="$(CXXFLAGS)" \
	-DCMAKE_CXX_COMPILER="$(CXX)"
yoga~/build/windows/%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)

windows/%/flex-ui.dll: LINKFLAGS += -shared
windows/%/flex-ui.dll: yoga~/build/windows/%/libyogacore.a | windows/%
	$(CXX) -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive $(CXXFLAGS) $(LINKFLAGS)

windows/x86_64/flex-ui.dll: CXX = x86_64-w64-mingw32-c++
windows/x86/flex-ui.dll: CXX = i686-w64-mingw32-c++


# Linux
yoga~/build/linux/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_FLAGS="$(CXXFLAGS)"
yoga~/build/linux/%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)

linux/%/flex-ui.so: CXXFLAGS += -fPIC
linux/%/flex-ui.so: LINKFLAGS += -shared
linux/%/flex-ui.so: yoga~/build/linux/%/libyogacore.a | linux/%
	$(CXX) -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive $(CXXFLAGS) $(LINKFLAGS)

linux/x86/flex-ui.so: CXXFLAGS += -m32


# macOS
yoga~/build/macos/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"
yoga~/build/macos/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)

osx/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64
osx/flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
osx/flex-ui.dylib: yoga~/build/macos/libyogacore.a | osx
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)


# iOS
yoga~/build/ios/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_OSX_ARCHITECTURES="arm64" \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_OSX_SYSROOT=iphoneos
yoga~/build/ios/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)

ios/flex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --sdk iphoneos --show-sdk-path)
ios/flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
ios/flex-ui.dylib: yoga~/build/ios/libyogacore.a | ios
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)


# Android
yoga~/build/android/%/libyogacore.a: CMAKE_FLAGS = \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_CXX_COMPILER="$(CXX)"
yoga~/build/android/%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) $(CMAKE_FLAGS)
	$(CMAKE_BIN) --build $(dir $@)

android/%/flex-ui.so: CXXFLAGS += -fPIC -static-libstdc++
android/%/flex-ui.so: LINKFLAGS += -shared
android/%/flex-ui.so: yoga~/build/android/%/libyogacore.a | android/%
	$(CXX) -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive $(CXXFLAGS) $(LINKFLAGS)

android/arm64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
android/arm32/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi19-clang++)
android/x86_64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
android/x86/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android19-clang++)


# Targets
windows-x86_64: windows/x86_64/flex-ui.dll
windows-x86: windows/x86/flex-ui.dll
linux-x86_64: linux/x86_64/flex-ui.so
linux-x86: linux/x86/flex-ui.so
macos-universal: osx/flex-ui.dylib
ios-arm64: ios/flex-ui.dylib
android-arm64: android/arm64/flex-ui.so
android-arm32: android/arm32/flex-ui.so
android-x86_64: android/x86_64/flex-ui.so
android-x86: android/x86/flex-ui.so
