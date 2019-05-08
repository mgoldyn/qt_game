#ifndef MOVING_OBJECT_H
#define MOVING_OBJECT_H

#include "input_structs.h"

#include <QObject>
#include <QGraphicsPixmapItem>

class moving_object : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    moving_object(const QString image_dir, const unsigned int step_size, const unsigned int tier);
    unsigned int step_size;
    unsigned int tier;
    virtual void set_attack_params(input_pack input) = 0;
public slots:
    virtual void move() = 0;
};

#endif // MOVING_OBJECT_H
