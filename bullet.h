#ifndef BULLET_H
#define BULLET_H

#include "moving_object.h"
#include "consts.h"
#include <QDebug>

class QMediaPlayer;

class bullet : public moving_object
{
    Q_OBJECT
public:
    bullet(const QString      image_dir = ":/images/kaczka.png",
           const unsigned int step_size = consts::step_size,
           const unsigned int tier      = 0)
        : moving_object(image_dir, step_size, tier){}
    void set_pos(const double x,
                 const double y);
    void sound(QMediaPlayer* bullet_sound);
    void set_attack_params(input_pack input);
    void set_bullet_trajectory();
    void move();
};

#endif // BULLET_H
