#include "player.h"
#include "bullet.h"
#include "consts.h"
#include "input_structs.h"
#include "enemy.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>

player::player()
{
    bullet_sound = new QMediaPlayer();
    this->bullet_tier = 1;
    bullet_sound->setMedia(QUrl("qrc:/sounds/jobro.wav"));
}

void player::add_bullet(const unsigned int tier      = 1,
                        const unsigned int step_size = consts::step_size,
                        const QString      image_dir = ":/images/kaczka.png")
{
    bullet* bull = new bullet(image_dir, step_size, tier);
    bull->set_attack_params(input_pack(x(), y(), bullet_sound));
    scene()->addItem(bull);
}

void player::make_bullets()
{
    switch (this->bullet_tier)
    {
        case 1:
        {
            add_bullet(1, 11);
            break;
        }

        case 2:
        {
            add_bullet(21, 7);
            add_bullet(22, 7);
            break;
        }

    case 3:
    {
        add_bullet(31, 20);
        add_bullet(32, 20);
        add_bullet(33, 20);
        break;
    }
    case 4:
        add_bullet(41, 15);
        add_bullet(42, 15);
        add_bullet(43, 15);
    }
}

void player::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Left)
        if(pos().x() - consts::step_size> 0)
            setPos(x() - consts::step_size, y());
    if(event->key() == Qt::Key_Right)
        if(pos().x() + consts::step_size + consts::player_width < consts::screen_width)
            setPos(x() + consts::step_size, y());
    if(event->key() == Qt::Key_Down)
        if(this->bullet_tier)
            this->bullet_tier--;
    if(event->key() == Qt::Key_Up)
        this->bullet_tier++;
    if(event->key() == Qt::Key_Space)
        make_bullets();
}

void player::mouseMoveEvent(QMouseEvent *event)
{
    this->pos() = event->pos();
}

void player::spawn()
{
    enemy* enemy_0 = new enemy();
    scene()->addItem(enemy_0);
}

