#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>

class moving_object : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    bool direction;

public:
    moving_object(const QString image_dir,
                  const unsigned int step_size,
                  const bool direction);
    unsigned int step_size;
public slots:
    virtual void move() = 0;
};

#endif // MOVING_OBJECT_H
