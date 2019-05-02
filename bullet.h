#ifndef BULLET_H
#define BULLET_H

#include "moving_object.h"
#include "consts.h"
#include <QDebug>

class bullet : public moving_object
{
    Q_OBJECT
public:
    bullet(const QString image_dir = ":/images/kaczka.png",
           const unsigned int step_size     = consts::step_size,
           const bool direction             = consts::direction_down)
        : moving_object(image_dir, step_size, direction){}
    void move();
};

#endif // BULLET_H
