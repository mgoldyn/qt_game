#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QGraphicsScene>

#include <QList>
extern game* game_0;
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
    setPos(x(), y() - this->step_size);
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
