#include <QImage>
#include <QPixmap>
#include "window.h"

Window::Window(QWidget *parent) {
	setWindowTitle("Test window");
	setStyleSheet("QLabel { background-color : white; color : blue; }");

	setText("This is a test");

    QImage image = QImage();
    image.load("test.png");

	setPixmap(QPixmap().fromImage(image));


}

void Window::keyPressEvent(QKeyEvent* event) {

}
