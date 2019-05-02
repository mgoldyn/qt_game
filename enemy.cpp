#include "enemy.h"
#include "game.h"
#include "QGraphicsScene"

extern game* game_0;
void enemy::move()
{
    setPos(x(), y() + this->step_size);
    if(pos().y() + rect().height() > consts::screen_height)
    {
        game_0->life_0->change_value(-1);
        scene()->removeItem(this);
        delete this;
    }
}
