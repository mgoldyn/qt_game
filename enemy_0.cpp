#include "enemy_0.h"
#include "bullet.h"
#include "game.h"

extern game* game_0;
//void enemy_0::collide_handle()
//{
//    QList<QGraphicsItem*> colliding_items = collidingItems();
//    for(int i = 0, n = colliding_items.size(); i < n; i++)
//    {
//        if(typeid(*(colliding_items[i])) == typeid(bullet))
//        {
//            scene()->removeItem(colliding_items[i]);
//            delete colliding_items[i];
//            this->hp--;

//            if(!this->hp)
//            {
//                game_0->score_0->change_value(1);
//                add_gift();
//                scene()->removeItem(this);
//                if(game_0->remaining_enemies-- == 0)
//                {
//                    game_0->enemy_counter = 0;
//                }
//                delete this;
//                return;
//            }
//        }

//        if(typeid(*(colliding_items[i])) == typeid(player))
//        {
//            game_0->score_0->change_value(-1);
//            game_0->life_0->change_value(-1);
//            scene()->removeItem(this);
//            if(game_0->remaining_enemies-- == 0)
//            {
//                game_0->enemy_counter = 0;
//            }
//            delete this;
//            return;
//        }

//    }
//}
