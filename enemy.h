#ifndef ENEMY_H
#define ENEMY_H

#include "moving_object.h"
#include "consts.h"
#include <stdlib.h>

class enemy : public moving_object
{
    Q_OBJECT
public:
    enemy(const QString image_dir = ":/images/kaczka.jpeg",
          const unsigned int step_size     = consts::step_size,
          const bool direction             = consts::direction_down)
       : moving_object(image_dir, step_size, direction)
    {
        moving_object::setPos(rand() % 700, 0);
    }
    void move();
};

#endif // ENEMY_H
