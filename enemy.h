#ifndef ENEMY_H
#define ENEMY_H

#include "moving_object.h"
#include "consts.h"
#include <stdlib.h>

class enemy : public moving_object
{
    Q_OBJECT
public:
    enemy(const unsigned int object_width  = consts::enemy0_width,
          const unsigned int object_height = consts::enemy0_height,
          const unsigned int step_size     = consts::enemy_step,
          const bool direction             = consts::direction_up)
        : moving_object(object_width, object_height, step_size, direction)
    {
        moving_object::setPos(rand() % 700, 0);
    }
    void move();
};

#endif // ENEMY_H
