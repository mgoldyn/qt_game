#ifndef BULLET_H
#define BULLET_H

#include "moving_object.h"
#include "consts.h"
#include <QDebug>

class bullet : public moving_object
{
    Q_OBJECT
public:
    bullet(const unsigned int object_width  = consts::bullet_width,
           const unsigned int object_height = consts::bullet_height,
           const unsigned int step_size     = consts::step_size,
           const bool direction             = consts::direction_down)
        : moving_object(object_width, object_height, step_size, direction){}
    void move();
};

#endif // BULLET_H
