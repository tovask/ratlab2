import QtQuick 2.0

Path{
    property PathView pathView

    property int frontStateWidth: 200

    //kezdőpont
    startX: 0
    startY: pathView.vertOff

    PathAttribute { name: "rotateY"; value: 50.0 }
    PathAttribute { name: "zOrder"; value: 1.0 }
    PathAttribute { name: "scale"; value: 0.7 }

    // egyenes vonal a p1-ig
    PathLine {
        x: pathView.width / 2 - frontStateWidth
        y: pathView.vertOff
    }

    // -- p1

    PathPercent { value: 0.44 }
    PathAttribute { name: "rotateY"; value: 50.0 }
    PathAttribute { name: "zOrder"; value: 10.0 }
    PathAttribute { name: "scale"; value: 0.7 }

    // görbe a p2-ig
    PathQuad {
        relativeX: frontStateWidth
        relativeY: 8
        relativeControlX: frontStateWidth/2
        relativeControlY: 8
    }

    // -- p2 (közép)

    PathPercent { value: 0.50 }
    PathAttribute { name: "rotateY"; value: 0.0 }
    PathAttribute { name: "zOrder"; value: 50.0 }
    PathAttribute { name: "scale"; value: 1.0 }

    // görbe a p3-ig
    PathQuad {
        relativeX: frontStateWidth
        relativeY: -8
        relativeControlX: frontStateWidth/2
        relativeControlY: -8
    }

    // -- p3

    PathPercent { value: 0.56 }
    PathAttribute { name: "rotateY"; value: -50.0 }
    PathAttribute { name: "zOrder"; value: 10.0 }
    PathAttribute { name: "scale"; value: 0.7 }

    // egyenes vonal a p4-ig
    PathLine {
        x: pathView.width / 2 + frontStateWidth
        y: pathView.vertOff
    }

    // -- p4

    // egyenes vonal a végpontig
    PathLine {
        x: pathView.width
        y: pathView.vertOff
    }

    PathAttribute { name: "rotateY"; value: -50.0 }
    PathAttribute { name: "zOrder"; value: 1.0 }
    PathAttribute { name: "scale"; value: 0.7 }
}
