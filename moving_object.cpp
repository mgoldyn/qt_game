#include "moving_object.h"
#include "consts.h"
#include <QTimer>
#include <QGraphicsScene>

moving_object::moving_object(const unsigned int object_width,
                             const unsigned int object_height,
                             const unsigned int step_size,
                             const bool direction)
{
    this->step_size = step_size;
    this->direction = direction;
    //    drew the rect
    setRect(consts::player_width / 2 - object_width / 2, 0, object_width, object_height);

    //    connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

//void moving_object::move()
//{
//    if(this->direction == false)
//    {
//        setPos(x(), y() - this->step_size);
//        if(pos().y() + rect().height() < 0)
//        {
//            scene()->removeItem(this);
//            delete this;
//        }
//    }
//    else
//    {
//        setPos(x(), y() + this->step_size);
//        if(pos().y() + rect().height() > consts::screen_height)
//        {
//            scene()->removeItem(this);
//            delete this;
//        }
//    }
//}
