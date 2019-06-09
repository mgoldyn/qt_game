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
    bullet(const QString image_dir      = ":/images/kaczka.png",
           const unsigned int step_size = consts::bullet_step,
           const unsigned int tier      = 0)
        : moving_object(image_dir, step_size, tier)
    {
    }
    void move();
    void set_attack_params(input_pack input);

};

#endif // BULLET_H
