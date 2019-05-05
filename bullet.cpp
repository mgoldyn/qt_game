#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QGraphicsScene>
#include <QMediaPlayer>

#include <QList>
extern game* game_0;

void bullet::set_pos(const double x,
                     const double y)
{
    this->setPos(x, y);
}

void bullet::sound(QMediaPlayer *bullet_sound)
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
    switch (this->tier)
    {
        case 1://level 1
        {
            set_pos(input.player_x  - 8 + consts::player_width / 2, input.player_y  - consts::bullet_height);
            break;
        }

        case 21://level 2
        {
            set_pos(input.player_x  - 8 + consts::player_width / 4, input.player_y - consts::bullet_height);
            break;
        }

        case 22:
        {
            set_pos(input.player_x - 8 + (3 * consts::player_width ) / 4, input.player_y - consts::bullet_height);
            break;
        }

        case 31:
        {
            set_pos(input.player_x + consts::player_width /  5, input.player_y - consts::bullet_height);
            break;
        }
        case 32:
        {
            set_pos(input.player_x + (2 * consts::player_width ) / 5, input.player_y - consts::bullet_height);
            break;
        }
        case 33:
        {
            set_pos(input.player_x + (3 * consts::player_width ) / 5, input.player_y - consts::bullet_height);
            break;
        }
        case 41:
        {
            set_pos(input.player_x + consts::player_width /  5, input.player_y - consts::bullet_height);
            break;
        }
        case 42:
        {
            set_pos(input.player_x + (2 * consts::player_width ) / 5, input.player_y - consts::bullet_height);
            break;
        }
        case 43:
        {
            set_pos(input.player_x + (3 * consts::player_width ) / 5, input.player_y - consts::bullet_height);
            break;
        }
    }
    sound(input.sound);
}

void bullet::set_bullet_trajectory()
{
    if(this->tier == 1  || this->tier == 21 || this->tier == 22 ||
       this->tier == 31 || this->tier == 32 || this->tier == 33 ||
       this->tier == 42)
        setPos(x(), y() - this->step_size);
    else
    {
        switch (this->tier)
        {
        case 41:
            setPos(x() - 3, y() - this->step_size);
            break;
        case 43:
            setPos(x() + 3, y() - this->step_size);
            break;
        }
    }

}

void bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(enemy))
        {
            game_0->score_0->change_value(1);
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    set_bullet_trajectory();
    if(pos().y() < 0 || pos().x() < 0 || pos().x() > consts::screen_width)
    {
        scene()->removeItem(this);
        delete this;
    }
}
