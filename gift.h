#ifndef GIFT_H
#define GIFT_H
#include "moving_object.h"
#include "consts.h"

class gift : public moving_object
{
    Q_OBJECT
public:
    gift(const QString image_dir      = ":/images/gift.png",
         const unsigned int step_size = consts::step_size,
         const unsigned int tier      = 0)
                 : moving_object(image_dir, step_size, tier)
             {
             }
void move();
void set_attack_params(input_pack input);
};

#endif // GIFT_H
