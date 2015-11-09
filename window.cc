#include <QImage>
#include <QPixmap>
#include <QDebug>
#include "window.h"

Window::Window(QWidget *parent) {
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

void Window::setImage(QString filename) {
    QImage image = QImage();

    image.load(filename);
    setPixmap(QPixmap().fromImage(image));
}

void Window::keyPressEvent(QKeyEvent* event) {
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

void Window::nextImage() {
    qDebug() << "Moving to next image";
    setImage(imglist->next());
}

void Window::prevImage() {
    qDebug() << "Moving to previoius image";
}

void Window::toggleFullscreen() {
    if (fullscreen)
        showNormal();
    else
        showFullScreen();

    fullscreen = !fullscreen;
}


// vim: ts=4 shiftwidth=4 expandtab
