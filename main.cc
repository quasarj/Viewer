#include <QDebug>
#include <QApplication>

#include "Viewer.h"

int main(int argc, char* argv[]) {
    qDebug() << "Qt5 Test, starting up..." << endl;

	QApplication app(argc, argv);
	Viewer win(NULL);
	win.show();
	return app.exec();

}
