#include "player.h"
#include "bullet.h"
#include "consts.h"
#include "enemy.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>

player::player()
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/jobro.wav"));
}

void player::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
        if(pos().x() - consts::step_size> 0)
        {
            setPos(x() - consts::step_size, y());
        }
        break;

    case Qt::Key_Right:
        if(pos().x() + consts::step_size + consts::player_width < consts::screen_width)
        {
            setPos(x() + consts::step_size, y());
        }
        break;

        case Qt::Key_Up:
            setPos(x(), y() - consts::step_size);
            break;

        case Qt::Key_Down:
            setPos(x(), y() + consts::step_size);
            break;

    case Qt::Key_Space:
        bullet* bull = new bullet();
        bull->setPos(x(), y() - consts::bullet_height);
        scene()->addItem(bull);
        bulletsound->play();
        break;
    }
}

void player::spawn()
{
    enemy* enemy_0 = new enemy();
    scene()->addItem(enemy_0);
}

