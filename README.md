# Flex UI
Flexible layout support for [Unity UI](https://docs.unity3d.com/Packages/com.unity.ugui@1.0/manual/index.html) using the [Yoga](https://yogalayout.dev/) layout engine.


## Features
- There is a single component you need: [FlexLayout](Runtime/FlexLayout.cs)
- `FlexLayout` only layouts children that also have a `FlexLayout` component, so you can still use anchors and other Layout Elements.
- Live updates in edit mode.


## Caveats
- Currently, the native library is build for macOS only


## How to install
Install directly using the [Unity Package Manager](https://docs.unity3d.com/Manual/upm-ui-giturl.html) with the following URL:
```
https://github.com/gilzoide/unity-flex-ui.git#1.0.0-preview1
```
