#ifndef ENEMY_0_H
#define ENEMY_0_H
#include "enemy.h"

class enemy_0: public enemy
{
public:
    enemy_0(const QString image_dir      = ":/images/enemy_1.png",
            const unsigned int step_size = consts::enemy_step,
            const unsigned int tier      = 3)
        : enemy(image_dir, step_size, tier){this->hp = tier;}
//    void collide_handle();
};

#endif // ENEMY_0_H
