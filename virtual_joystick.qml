import QtQuick 2.1

Rectangle {
    id: rectangle
    width: joystick.width
    height: joystick.height
    visible: true

    signal joystick_moved(double x, double y);

    Image {
        id: joystick

        property real angle : 0
        property real distance : 0

        source: "background.png"
        anchors.centerIn: parent

        ParallelAnimation {
            id: returnAnimation
            NumberAnimation { target: thumb.anchors; property: "horizontalCenterOffset";
                to: 0; duration: 200; easing.type: Easing.OutSine }
            NumberAnimation { target: thumb.anchors; property: "verticalCenterOffset";
                to: 0; duration: 200; easing.type: Easing.OutSine }
        }


        ParallelAnimation {
            id: nudgeAnimation
            NumberAnimation { target: thumb.anchors; property: "horizontalCenterOffset";
                to: 1; duration: 1; easing.type: Easing.OutSine }
            NumberAnimation { target: thumb.anchors; property: "verticalCenterOffset";
                to: 1; duration: 1; easing.type: Easing.OutSine }
        }

        MouseArea {
            id: mouse
            property real fingerAngle : Math.atan2(mouseX, mouseY)
            property int mcx : mouseX - width * 0.5
            property int mcy : mouseY - height * 0.5
            property bool fingerOutOfBounds : fingerDistance2 < distanceBound2
            property real fingerDistance2 : mcx * mcx + mcy * mcy
            property real distanceBound : width * 0.5 - thumb.width * 0.5
            property real distanceBound2 : distanceBound * distanceBound

            property double signal_x : (mouseX - joystick.width/2) / distanceBound
            property double signal_y : -(mouseY - joystick.height/2) / distanceBound

            anchors.fill: parent

            onPressed: returnAnimation.stop()
            onReleased: {
                returnAnimation.restart()
                joystick_moved(0, 0);
            }
            onPositionChanged: {
                if (fingerOutOfBounds) {
                    thumb.anchors.horizontalCenterOffset = mcx
                    thumb.anchors.verticalCenterOffset = mcy
                } else {
                    var angle = Math.atan2(mcy, mcx)
                    thumb.anchors.horizontalCenterOffset = Math.cos(angle) * distanceBound
                    thumb.anchors.verticalCenterOffset = Math.sin(angle) * distanceBound
                }

                // Fire the signal to indicate the joystick has moved
                angle = Math.atan2(signal_y, signal_x)
                joystick_moved(Math.cos(angle), Math.sin(angle));
            }
        }

        Image {
            id: thumb
            source: "finger.png"
            anchors.centerIn: parent
        }
    }

    // HACK ajs 03/Mar/14 - Nudge an image to force the QML to redraw itself
    // without this the QML widget does not show intially
    Component.onCompleted: nudgeAnimation.start(), returnAnimation.start();
}
