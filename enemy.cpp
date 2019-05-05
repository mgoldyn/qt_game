#include "enemy.h"
#include "game.h"
#include "QGraphicsScene"
#include "QApplication"
#include "QList"

extern game* game_0;
void enemy::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(player))
        {
            game_0->score_0->change_value(1);
            game_0->life_0->change_value(-1);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(), y() + this->step_size);
    if(pos().y() > consts::screen_height)
    {
        game_0->life_0->change_value(-1);
        scene()->removeItem(this);
        delete this;
    }
    if(!game_0->life_0->get_value())
    {
        QApplication::quit();
    }
}
