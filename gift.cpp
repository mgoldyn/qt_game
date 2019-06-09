#include "gift.h"
#include "player.h"
#include "game.h"
#include "QList"

extern game * game_0;

void gift::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(player))
        {   if (game_0->player_0->bullet_tier < 6)
            {
                game_0->player_0->tier_up();
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(), y() + step_size);
    if(pos().y() >= consts::screen_height)
        delete this;
}

void gift::set_attack_params(input_pack input)
{
    setPos(input.player_x, input.player_y);
}
