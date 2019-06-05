#include "moving_object.h"
#include "consts.h"
#include <QTimer>
#include <QGraphicsScene>

moving_object::moving_object(const QString image_dir,
                             const unsigned int step_size,
                             const unsigned int tier)
{
    this->step_size = step_size;
    this->tier      = tier;
    QTimer* timer   = new QTimer();

    setPixmap(QPixmap(image_dir));
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

// void moving_object::move()
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
