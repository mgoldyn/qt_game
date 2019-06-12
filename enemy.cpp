#include "enemy.h"
#include "game.h"
#include "bullet.h"
#include "gift.h"
#include "QGraphicsScene"
#include "QApplication"
#include "QList"

extern game* game_0;
void enemy::add_gift()
{
    if(1 + rand()%4 == 2)
    {
        gift* gift_0 = new gift();
        gift_0->set_attack_params(input_pack(this->x(),this->y()));
        scene()->addItem(gift_0);
    }
}

void enemy::find_direction()
{
    if(pos().y() > consts::screen_height)
    {
        direction_y = true;
    }
    else if(pos().y() < 0)
    {
        direction_y = false;
    }
    if(pos().x() < 0)
    {
        direction_x = true;
    }
    else if(pos().x() > consts::screen_width)
    {
        direction_x = false;
    }
}
void enemy::set_pos()
{
    if(direction_x && !direction_y)
    {
        setPos(x() + 1, y() + this->step_size);
    }
    else if(direction_x && direction_y)
    {
        setPos(x() + 1, y() - this->step_size);
    }
    else if(!direction_x && direction_y)
    {
        setPos(x() - 1, y() - this->step_size);
    }
    else
    {
        setPos(x() - 1, y() + this->step_size);
    }
}

enemy::enemy(const QString image_dir, const unsigned int step_size, const unsigned int tier)
    : moving_object(image_dir, step_size, tier)
{
    this->direction_x = false;
    this->direction_y = false;
    moving_object::setPos(rand() % 700, 0);
}

void enemy::collide_handle()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(bullet))
        {
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            this->hp--;

            if(!this->hp)
            {
                game_0->score_0->change_value(1);
                add_gift();
                scene()->removeItem(this);
                if(game_0->remaining_enemies-- == 0)
                {
                    game_0->enemy_counter = 0;
                }
                delete this;
                return;
            }
        }

        if(typeid(*(colliding_items[i])) == typeid(player))
        {
            game_0->score_0->change_value(-1);
            game_0->life_0->change_value(-1);
            scene()->removeItem(this);
            if(game_0->remaining_enemies-- == 0)
            {
                game_0->enemy_counter = 0;
            }
            delete this;
            return;
        }

    }
}
void enemy::move()
{
    collide_handle();
    find_direction();
    set_pos();

    if(!game_0->life_0->get_value())
    {
        QApplication::quit();
    }
}
