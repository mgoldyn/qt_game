#include "enemy0.h"
#include "consts.h"
#include <QTimer>
#include <QGraphicsScene>

enemy0::enemy0()
{
    //    drew the rect
    setRect(consts::player_width / 2 - consts::enemy0_width / 2,
            0,
            consts::enemy0_width,
            consts::enemy0_height);

    //    connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void enemy0::move()
{
    setPos(x(), y() - consts::step_size);
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
