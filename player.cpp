#include "player.h"
#include "bullet.h"
#include "consts.h"
#include "input_structs.h"
#include "enemy.h"
#include "game.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QMediaPlayer>

player::player(game* game0)
{
    this->setPixmap(QPixmap(":/images/gracz.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    this->game0       = game0;
    this->bullet_tier = 1;
    bullet_sound      = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/sounds/jobro.wav"));
}

void player::tier_up()
{
    this->bullet_tier++;
}

void player::add_bullet(const unsigned int tier      = 1,
                        const unsigned int step_size = consts::step_size,
                        const QString image_dir      = ":/images/kaczka.png")
{
    bullet* bull = new bullet(image_dir, step_size, tier);
    bull->set_attack_params(input_pack(this->x(), this->y(), bullet_sound));
    scene()->addItem(bull);
}

void player::make_bullets()
{
    switch(this->bullet_tier)
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
        break;
    case 5:
        add_bullet(51,15);
        add_bullet(52,15);
        add_bullet(53,15);
        add_bullet(54,15);
        break;
    case 6:
        add_bullet(61,15);
        add_bullet(62,15);
        add_bullet(63,15);
        add_bullet(64,15);
        add_bullet(65,15);
        break;
    case 7:
        add_bullet(71,15);
        add_bullet(72,15);
        add_bullet(73,15);
        add_bullet(74,15);
        add_bullet(75,15);
        add_bullet(75,15);
        add_bullet(75,15);
        break;

    }
}

void player::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Left)
        if(pos().x() - consts::step_size > 0)
            setPos(x() - consts::step_size, y());
    if(event->key() == Qt::Key_Right)
        if(pos().x() + consts::step_size + consts::player_width < consts::screen_width)
            setPos(x() + consts::step_size, y());
    if(event->key() == Qt::Key_Down)
    {
        if(pos().y() < 800)
            setPos(x(), y() + consts::step_size);
        this->bullet_tier--;
    }
    if(event->key() == Qt::Key_Up)
    {
        if(pos().y() > 0)
            setPos(x(), y() - consts::step_size);
        this->bullet_tier++;
    }
    if(event->key() == Qt::Key_Space)
        make_bullets();
    if(event->key() == Qt::Key_K)
        if(this->bullet_tier)
            this->bullet_tier--;
    if(event->key() == Qt::Key_L)
        this->bullet_tier++;
}
