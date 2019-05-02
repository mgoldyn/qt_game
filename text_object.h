#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include <QGraphicsTextItem>

class text: public QGraphicsTextItem
{
    int value;
    QString name;
public:
    text(QGraphicsItem * parent = nullptr,
                const QString name = nullptr,
                const unsigned int colour = Qt::blue,
                const int font_size = 16);
    int get_value();
    int change_value(int change);
};

#endif // TEXT_OBJECT_H
