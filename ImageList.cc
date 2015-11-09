#include <QDebug>
#include <QDir>

class ImageList {
public:
    ImageList(QString path) {
        qDebug() << "Starting up the ImageList!";

        load(path);
        pos = -1;
        this->path = path;
    }

    QString next() {
        if (pos >= images.length() - 1)
            pos = -1;
        return path + "/" + images[++pos];
    }

    QString prev() {
        if (pos <= 0)
            pos = images.length();
        return path + "/" + images[--pos];
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
