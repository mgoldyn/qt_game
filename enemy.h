#ifndef ENEMY_H
#define ENEMY_H

#include "moving_object.h"
#include "consts.h"
#include <stdlib.h>
#include <QMediaPlayer>
class enemy : public moving_object
{
    Q_OBJECT
    bool direction_x;
    bool direction_y;
    void add_gift();
    void find_direction();
    void set_pos();
    void collide_handle();
    void set_attack_params(input_pack input)
    {
        input.sound->stop();
    }

public:
    unsigned int hp;
    enemy(const QString image_dir      = ":/images/enemy_1.png",
          const unsigned int step_size = consts::enemy_step,
          const unsigned int tier      = 0);
    void move();
};

#endif // ENEMY_H
