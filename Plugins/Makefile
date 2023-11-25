CMAKE_BIN ?= cmake

BUILD_DIRS = \
	osx \
	linux/x86_64 linux/x86

$(BUILD_DIRS):
	mkdir -p $@

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
linux64: linux/x86_64/flex-ui.so
linux32: linux/x86/flex-ui.so
macos: osx/flex-ui.dylib
