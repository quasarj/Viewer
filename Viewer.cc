#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "Viewer.h"

Viewer::Viewer(QWidget *parent) {
    if (parent) {
        // silence the warning about not using parent. yeeeeah this is dumb.
    }

    fullscreen = false;

    setWindowTitle("cImageViewer");
    setStyleSheet("QLabel { background-color : white; color : blue; }");

    setText("This is a test");

    imglist = new ImageList("images");


    setImage(imglist->next());
}

void Viewer::setImage(QString filename) {
    QImage image = QImage();

    image.load(filename);
    setPixmap(QPixmap().fromImage(image));
}

void Viewer::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Q:
            close();
            break;
        case Qt::Key_Right:
            nextImage();
            break;
        case Qt::Key_Left:
            prevImage();
            break;

        case Qt::Key_F:
            toggleFullscreen();
            break;

    }

    // Probably don't need this
    //QLabel::keyPressEvent(event);
}

void Viewer::nextImage() {
    qDebug() << "Moving to next image";
    setImage(imglist->next());
}

void Viewer::prevImage() {
    qDebug() << "Moving to previoius image";
    setImage(imglist->prev());
}

void Viewer::toggleFullscreen() {
    if (fullscreen)
        showNormal();
    else
        showFullScreen();

    fullscreen = !fullscreen;
}


// vim: ts=4 shiftwidth=4 expandtab
