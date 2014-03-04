# QMLVirtualJoystick

An example of embedding a QML Virtual Joystick within a Qt form.

![Screenshot of program](https://raw.github.com/aaronsnoswell/QMLVirtualJoystick/master/screen_shot.png)

## Introduction

I've patched together examples at
[http://qt-project.org/forums/viewthread/21118](http://qt-project.org/forums/viewthread/21118)
and [http://kunalmaemo.blogspot.com.au/2011/11/virtual-joystick-with-qml.html](http://qt-project.org/forums/viewthread/21118)
and other places to create a stand-alone project that demonstrates how to
create a simple virtual joystick.

Released under the Apache 2.0 Licence.

## Usage

Open `QMLVirtualJoystick.pro` in Qt Creator and configure the project for your
kit(s). Run the sample. When clicking and dragging in the virtual joystick,
you should see the current mouse position displayed in the `qDebug()` console.

Requires Qt 5.1.1+

Tested on Mac OSX 10.9.1 and Windows 7, 64 bit.

## Licence

Copyright 2014 Aaron Snoswell

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
