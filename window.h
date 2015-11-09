#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class Window: public QLabel {
public:
		Window(QWidget*);
		void keyPressEvent(QKeyEvent*);
};
