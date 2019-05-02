#ifndef ENEMY0_H
#define ENEMY0_H

#include <QGraphicsRectItem>
#include <QObject>

class enemy0 : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemy0();
public slots:
    void move();
};

#endif // ENEMY0_H
