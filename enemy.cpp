#include "enemy.h"
#include "game.h"
#include "QGraphicsScene"
#include "QApplication"
#include "QList"

extern game* game_0;
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
        direction_x = false;
    }
    else if(pos().x() > consts::screen_width)
    {
        direction_x = true;
    }
}
void enemy::set_pos()
{
    if(!direction_x && !direction_y)
    {
        setPos(x() + 4, y() + this->step_size);
    }
    else if(!direction_x && direction_y)
    {
        setPos(x() + 4, y() - this->step_size);
    }
    else if(direction_x && direction_y)
    {
        setPos(x() - 4, y() - this->step_size);
    }
    else
    {
        setPos(x() - 4, y() + this->step_size);
    }
}
void enemy::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(player))
        {
            game_0->score_0->change_value(-1);
            game_0->life_0->change_value(-1);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    find_direction();
    set_pos();

    if(!game_0->life_0->get_value())
    {
        QApplication::quit();
    }
}
