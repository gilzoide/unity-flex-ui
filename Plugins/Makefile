CMAKE_BIN ?= cmake

BUILD_DIRS = osx

$(BUILD_DIRS):
	mkdir -p $@

# macOS
yoga~/build/macos:
	$(CMAKE_BIN) yoga~/yoga -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -B $@ -G "Unix Makefiles"
yoga~/build/macos/libyogacore.a: | yoga~/build/macos
	$(MAKE) -C $|

osx/flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64
osx/flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
osx/flex-ui.dylib: yoga~/build/macos/libyogacore.a | osx
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)

macos: osx/flex-ui.dylib
