# QMLVirtualJoystick

An example of embedding a QML Virtual Joystick within a Qt form.

## Introduction

I've patched together examples at
[http://qt-project.org/forums/viewthread/21118](http://qt-project.org/forums/viewthread/21118)
and [http://kunalmaemo.blogspot.com.au/2011/11/virtual-joystick-with-qml.html](http://qt-project.org/forums/viewthread/21118)
and other places to create a stand-along project that demonstrates how to
create a simple virtual joystick.

## Usage

Open `QMLVirtualJoystick.pro` in Qt Creator and configure the project for your
kit(s). Run the sample. When clicking and dragging in the virtual joystick,
you should see the current mouse position displayed in the `qDebug()` console.

Requires Qt 5.1.1+

Tested on Mac OSX 10.9.1
