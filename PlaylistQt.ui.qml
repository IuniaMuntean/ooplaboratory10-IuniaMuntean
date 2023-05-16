

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import UntitledProject

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Text {
        id: text1
        x: 156
        y: 28
        width: 459
        height: 59
        text: qsTr("All Songs")
        font.pixelSize: 30
        verticalAlignment: Text.AlignBottom
        scale: 1
    }

    TextInput {
        id: textInput
        x: 319
        y: 633
        width: 463
        height: 38
        text: qsTr("")
        font.pixelSize: 28
        renderType: Text.QtRendering
        font.weight: Font.Normal
    }

    TextField {
        id: textField
        x: 156
        y: 93
        width: 626
        height: 495
        font.pointSize: 26
        placeholderText: qsTr("Text Field")
    }

    Text {
        id: text2
        x: 170
        y: 634
        width: 143
        height: 35
        text: qsTr("Title:")
        font.pixelSize: 26
        horizontalAlignment: Text.AlignLeft
    }

    TextInput {
        id: textInput1
        x: 319
        y: 688
        width: 463
        height: 38
        text: qsTr("")
        font.pixelSize: 28
        renderType: Text.QtRendering
        font.weight: Font.Normal
    }

    Text {
        id: text3
        x: 170
        y: 689
        width: 143
        height: 35
        text: qsTr("Artist:")
        font.pixelSize: 26
        horizontalAlignment: Text.AlignLeft
    }

    TextInput {
        id: textInput2
        x: 319
        y: 745
        width: 463
        height: 38
        text: qsTr("")
        font.pixelSize: 28
        renderType: Text.QtRendering
        font.weight: Font.Normal
    }

    Text {
        id: text4
        x: 170
        y: 745
        width: 143
        height: 35
        text: qsTr("Duration:")
        font.pixelSize: 26
        horizontalAlignment: Text.AlignLeft
    }

    TextInput {
        id: textInput3
        x: 319
        y: 804
        width: 463
        height: 38
        text: qsTr("")
        font.pixelSize: 28
        renderType: Text.QtRendering
        font.weight: Font.Normal
    }

    Text {
        id: text5
        x: 170
        y: 804
        width: 143
        height: 35
        text: qsTr("Link:")
        font.pixelSize: 26
        horizontalAlignment: Text.AlignLeft
    }

    Button {
        id: button
        x: 146
        y: 886
        width: 153
        height: 50
        text: qsTr("Add")
        font.pointSize: 19
    }

    Button {
        id: button1
        x: 347
        y: 886
        width: 153
        height: 50
        text: qsTr("Delete")
        font.pointSize: 19
    }

    Button {
        id: button2
        x: 546
        y: 886
        width: 153
        height: 50
        text: qsTr("Update")
        font.pointSize: 19
    }

    Button {
        id: button3
        x: 347
        y: 963
        width: 153
        height: 50
        text: qsTr("Filter")
        font.pointSize: 19
    }

    Button {
        id: button4
        x: 876
        y: 515
        width: 153
        height: 50
        text: qsTr(">")
        font.pointSize: 25
    }

    Text {
        id: text6
        x: 1152
        y: 28
        width: 459
        height: 59
        text: qsTr("Playlist")
        font.pixelSize: 30
        verticalAlignment: Text.AlignBottom
        scale: 1
    }

    TextField {
        id: textField1
        x: 1152
        y: 113
        width: 595
        height: 729
        font.pointSize: 26
        placeholderText: qsTr("Text Field")
    }

    Button {
        id: button5
        x: 1152
        y: 963
        width: 290
        height: 50
        text: qsTr("Play")
        font.pointSize: 22
    }

    Button {
        id: button6
        x: 1457
        y: 963
        width: 290
        height: 50
        text: qsTr("Next")
        font.pointSize: 22
    }
    states: [
        State {
            name: "clicked"
            when: button.checked
        }
    ]
}
