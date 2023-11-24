CMAKE_BIN ?= cmake

# macOS
yoga~/build/macos:
	$(CMAKE_BIN) yoga~/yoga -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" -B $@ -G "Unix Makefiles"
yoga~/build/macos/libyogacore.a: | yoga~/build/macos
	$(MAKE) -C $|

flex-ui.dylib: CXXFLAGS += -arch x86_64 -arch arm64
flex-ui.dylib: LINKFLAGS += -shared -Wl,-all_load
flex-ui.dylib: yoga~/build/macos/libyogacore.a
	$(CXX) -o $@ $< $(CXXFLAGS) $(LINKFLAGS)
