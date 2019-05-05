#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "text_object.h"

#include <QGraphicsView>
#include <QGraphicsScene>

class game : public QGraphicsView
{
public:
    game();
    QApplication* app ;
    QGraphicsScene* scene;
    player* player0;
    text* score_0;
    text* life_0;
};

#endif // GAME_H
