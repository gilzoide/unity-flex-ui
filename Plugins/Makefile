CMAKE_BIN ?= cmake

BUILD_DIRS = osx

$(BUILD_DIRS):
	mkdir -p $@

# macOS
yoga~/build/macos/libyogacore.a:
	$(CMAKE_BIN) -S yoga~/yoga -B $(dir $@) -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -DCMAKE_BUILD_TYPE=Release
	$(CMAKE_BIN) --build $(dir $@)

osx/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64
osx/flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
osx/flex-ui.dylib: yoga~/build/macos/libyogacore.a | osx
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)

# Targets
macos: osx/flex-ui.dylib
