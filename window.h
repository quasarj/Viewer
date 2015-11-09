#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

#include <ImageList.cc>

class Window: public QLabel {
private:
		bool fullscreen;
		ImageList* imglist;
public:
		Window(QWidget*);
		void nextImage();
		void prevImage();
		void toggleFullscreen();
		void setImage(QString);
protected:
		void keyPressEvent(QKeyEvent*);
};
