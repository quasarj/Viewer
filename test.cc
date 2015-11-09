#include <QDebug>
#include <QApplication>

#include "window.h"

int main(int argc, char* argv[]) {
    qDebug() << "Qt5 Test, starting up..." << endl;

	QApplication app(argc, argv);
	Window win(NULL);
	win.show();
	return app.exec();

}
