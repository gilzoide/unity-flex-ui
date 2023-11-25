CMAKE_BIN ?= cmake

BUILD_DIRS = \
	windows/x86_64 windows/x86 \
	linux/x86_64 linux/x86 \
	osx

# Misc
$(BUILD_DIRS):
	mkdir -p $@


# Windows
yoga~/build/windows/%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="$(CXXFLAGS)" -DCMAKE_CXX_COMPILER="$(CXX)"
	$(CMAKE_BIN) --build $(dir $@)

windows/%/flex-ui.dll: LINKFLAGS += -shared
windows/%/flex-ui.dll: yoga~/build/windows/%/libyogacore.a | windows/%
	$(CXX) -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive $(CXXFLAGS) $(LINKFLAGS)

windows/x86_64/flex-ui.dll: CXX = x86_64-w64-mingw32-c++
windows/x86/flex-ui.dll: CXX = i686-w64-mingw32-c++


# Linux
yoga~/build/linux/%/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="$(CXXFLAGS)"
	$(CMAKE_BIN) --build $(dir $@)

linux/%/flex-ui.so: CXXFLAGS += -fPIC
linux/%/flex-ui.so: LINKFLAGS += -shared
linux/%/flex-ui.so: yoga~/build/linux/%/libyogacore.a | linux/%
	$(CXX) -o $@ -Wl,--whole-archive $< -Wl,--no-whole-archive $(CXXFLAGS) $(LINKFLAGS)

linux/x86/flex-ui.so: CXXFLAGS += -m32


# macOS
yoga~/build/macos/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DCMAKE_BUILD_TYPE=Release
	$(CMAKE_BIN) --build $(dir $@)

osx/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64
osx/flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
osx/flex-ui.dylib: yoga~/build/macos/libyogacore.a | osx
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)


# Targets
windows64: windows/x86_64/flex-ui.dll
windows32: windows/x86/flex-ui.dll
linux64: linux/x86_64/flex-ui.so
linux32: linux/x86/flex-ui.so
macos: osx/flex-ui.dylib
