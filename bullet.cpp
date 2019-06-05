#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "gift.h"
#include <QGraphicsScene>
#include <QMediaPlayer>

#include <QList>
extern game* game_0;

//check if bullet should go right, left or forward
bool bullet::is_forward()
{
   return this->tier == 1 || this->tier == 21 || this->tier == 22 || this->tier == 31 ||
           this->tier == 32 || this->tier == 33 || this->tier == 42 || this->tier == 63;
}

bool bullet::is_left()
{
    return tier == 41 || tier == 51 || tier == 52 || tier == 61 || tier == 62;
}

bool bullet::is_right()
{
    return tier == 43 || tier == 53 || tier == 54 || tier == 64 || tier == 65;
}

//set pos relative to player
void bullet::set_relative_pos(const input_pack input,
                              const std::tuple<uint32, uint32> rel_pos)
{
    set_pos(input.player_x + (std::get<0>(rel_pos) * consts::player_width) / std::get<1>(rel_pos),
            input.player_y - consts::bullet_height);
}

void bullet::set_pos(const double x, const double y)
{
    this->setPos(x, y);
}

void bullet::sound(QMediaPlayer* bullet_sound)
{
    if(bullet_sound->state() == QMediaPlayer::PlayingState)
    {
        bullet_sound->setPosition(0);
    }
    else
    {
        bullet_sound->play();
    }
}

void bullet::set_attack_params(input_pack input)
{
    switch(this->tier)
    {
    case 1: // level 1
    {
        set_relative_pos(input, consts::bullet::t1_center_pos);
        break;
    }

    case 21: // level 2
    {
        set_relative_pos(input, consts::bullet::t2_left_pos);
        break;
    }

    case 22:
    {
        set_relative_pos(input, consts::bullet::t2_right_pos);
        break;
    }

    case 31:
    {
        set_relative_pos(input, consts::bullet::t3_left_pos);
        break;
    }
    case 32:
    {
        set_relative_pos(input, consts::bullet::t3_center_pos);
        break;
    }
    case 33:
    {
        set_relative_pos(input, consts::bullet::t3_right_pos);
        break;
    }
    case 41:
    {
        set_relative_pos(input, consts::bullet::t4_left_pos);
        break;
    }
    case 42:
    {
        set_relative_pos(input, consts::bullet::t4_center_pos);
        break;
    }
    case 43:
    {
        set_relative_pos(input, consts::bullet::t4_right_pos);
        break;
    }
    case 51:
    {
        set_relative_pos(input, consts::bullet::t5_l_left_pos);
        break;
    }
    case 52:
    {
        set_relative_pos(input, consts::bullet::t5_left_pos);
        break;
    }
    case 53:
    {
        set_relative_pos(input, consts::bullet::t5_right_pos);
        break;
    }
    case 54:
    {
        set_relative_pos(input, consts::bullet::t5_r_right_pos);
        break;
    }
    case 61:
    {
        set_relative_pos(input, consts::bullet::t6_l_left_pos);
        break;
    }
    case 62:
    {
        set_relative_pos(input, consts::bullet::t6_left_pos);
        break;
    }
    case 63:
    {
        set_relative_pos(input, consts::bullet::t6_center_pos);
        break;
    }
    case 64:
    {
        set_relative_pos(input, consts::bullet::t6_right_pos);
        break;
    }
    case 65:
    {
        set_relative_pos(input, consts::bullet::t6_r_right_pos);
        break;
    }
    }

    sound(input.sound);
}

void bullet::set_bullet_trajectory()
{
    if(is_forward())
    {
        setPos(x(), y() - this->step_size);
    }
    else if(is_left())
    {
        setPos(x() - 3, y() - this->step_size);
    }
    else if(is_right())
    {
        setPos(x() + 3, y() - this->step_size);
    }
    else
    {
        setPos(x(), y() - this->step_size);
    }
}

void bullet::move()
{
    set_bullet_trajectory();

    if(pos().y() < 0 || pos().x() < 0 || pos().x() > consts::screen_width)
    {
        scene()->removeItem(this);
        delete this;
    }
}
