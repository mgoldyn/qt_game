#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include <QObject>
#include <QGraphicsRectItem>

class moving_object : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    bool direction;

public:
    moving_object(const unsigned int object_width,
                  const unsigned int object_height,
                  const unsigned int step_size,
                  const bool direction);
    unsigned int step_size;
public slots:
    virtual void move() = 0;
};

#endif // MOVING_OBJECT_H
