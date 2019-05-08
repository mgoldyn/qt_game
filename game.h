#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "text_object.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>

class game : public QGraphicsView
{
private:
    friend class player;
    unsigned int enemy_counter;
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

public:
    game();
    bool do_spawn;
    QApplication* app;
    QGraphicsScene* scene;
    player* player_0 = nullptr;
    text* score_0;
    text* life_0;
    QTimer* timer_0;
};

#endif // GAME_H
