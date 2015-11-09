#include <QDebug>
#include <QDir>

class ImageList {
public:
    ImageList(QString path) {
        qDebug() << "Starting up the ImageList!";

        load(path);
        pos = 0;
        this->path = path;
    }

    QString next() {
        // return path + QString("/") + images[pos++];
        return path + "/" + images[pos++];
    }

private:

    QStringList images;
    QString path;
    int pos;

    bool load(QString path) {
        QStringList filters;
        filters << "*.png" << "*.jpg";

        QDir dir(path);
        dir.setNameFilters(filters);

        images = dir.entryList();


        return true;
    }
};


// vim: ts=4 shiftwidth=4 expandtab
