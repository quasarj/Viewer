#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

#include <ImageList.cc>

class Viewer: public QLabel {
private:
		bool fullscreen;
		ImageList* imglist;
public:
		Viewer(QWidget*);
		void nextImage();
		void prevImage();
		void toggleFullscreen();
		void setImage(QString);
protected:
		void keyPressEvent(QKeyEvent*);
};
