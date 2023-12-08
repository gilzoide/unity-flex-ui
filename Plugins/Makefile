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
	build/linux/x86_64 build/linux/x86 \
	build/macos build/ios build/tvos \
	build/android/arm64 build/android/arm32 build/android/x86 build/android/x86_64 \
	build/webgl

# Misc
$(BUILD_DIRS):
	mkdir -p $@

%/flex-ui.dll: src~/flex-ui.cpp | %
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/flex-ui.so: CXXFLAGS += -fPIC
%/flex-ui.so: src~/flex-ui.cpp | %
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

%/flex-ui.dylib: src~/flex-ui.cpp | %
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LINKFLAGS)
	$(STRIP) -x $@

# Linux
build/linux/x86/flex-ui.so: CXXFLAGS += -m32

# macOS
build/macos/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64

# iOS
build/ios/flex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk iphoneos)

# tvOS
build/tvos/flex-ui.dylib: CXXFLAGS += -arch arm64 -isysroot $(shell xcrun --show-sdk-path --sdk appletvos)

# Android
build/android/%/flex-ui.so: CXXFLAGS += -static-libstdc++
build/android/%/flex-ui.so: STRIP = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/llvm-strip)

build/android/arm64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/aarch64-linux-android21-clang++)
build/android/arm32/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/armv7a-linux-androideabi19-clang++)
build/android/x86_64/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/x86_64-linux-android21-clang++)
build/android/x86/flex-ui.so: CXX = $(wildcard $(ANDROID_NDK_ROOT)/toolchains/llvm/prebuilt/*/bin/i686-linux-android19-clang++)

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

linux-x86_64: build/linux/x86_64/flex-ui.so
linux-x86: build/linux/x86/flex-ui.so

macos-universal: build/macos/flex-ui.dylib
ios-arm64: build/ios/flex-ui.dylib
tvos-arm64: build/tvos/flex-ui.dylib

android-arm64: build/android/arm64/flex-ui.so
android-arm32: build/android/arm32/flex-ui.so
android-x86_64: build/android/x86_64/flex-ui.so
android-x86: build/android/x86/flex-ui.so

webgl: build/webgl/flex-ui.bc
