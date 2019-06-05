#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "gift.h"
#include <QGraphicsScene>
#include <QMediaPlayer>

#include <QList>
extern game* game_0;

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

void bullet::set_relative_pos(const input_pack input,
                              const unsigned rel_a,
                              const unsigned rel_b)
{
    set_pos(input.player_x + (rel_a * consts::player_width) / rel_b,
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
        set_relative_pos(input, 2, 5);
        break;
    }

    case 21: // level 2
    {
        set_relative_pos(input, 1, 5);
        break;
    }

    case 22:
    {
        set_relative_pos(input, 3, 5);
        break;
    }

    case 31:
    {
        set_relative_pos(input, 1, 5);
        break;
    }
    case 32:
    {
        set_relative_pos(input, 2, 5);
        break;
    }
    case 33:
    {
        set_relative_pos(input, 3, 5);
        break;
    }
    case 41:
    {
        set_relative_pos(input, 1, 5);
        break;
    }
    case 42:
    {
        set_relative_pos(input, 2, 5);
        break;
    }
    case 43:
    {
        set_relative_pos(input, 3, 5);
        break;
    }
    case 51:
    {
        set_relative_pos(input, 1, 6);
        break;
    }
    case 52:
    {
        set_relative_pos(input, 2, 6);
        break;
    }
    case 53:
    {
        set_relative_pos(input, 3, 6);
        break;
    }
    case 54:
    {
        set_relative_pos(input, 4, 6);
        break;
    }
    case 61:
    {
        set_relative_pos(input, 1, 7);
        break;
    }
    case 62:
    {
        set_relative_pos(input, 2, 7);
        break;
    }
    case 63:
    {
        set_relative_pos(input, 3, 7);
        break;
    }
    case 64:
    {
        set_relative_pos(input, 4, 7);
        break;
    }
    case 65:
    {
        set_relative_pos(input, 5, 7);
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
