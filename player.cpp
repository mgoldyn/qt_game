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
    if(bullet_tier < consts::bullet::max_tier)
    {
        bullet_tier++;
    }
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
        add_bullet(1, 7);
        break;
    }
    case 2:
    {
        add_bullet(21, 9);
        add_bullet(22, 9);
        break;
    }
    case 3:
    {
        add_bullet(31, 14);
        add_bullet(32, 14);
        add_bullet(33, 14);
        break;
    }
    case 4:
        add_bullet(41, 15);
        add_bullet(42, 15);
        add_bullet(43, 15);
        break;
    case 5:
        add_bullet(51,25);
        add_bullet(52,25);
        add_bullet(53,25);
        add_bullet(54,25);
        break;
    case 6:
        add_bullet(61,27);
        add_bullet(62,27);
        add_bullet(63,27);
        add_bullet(64,27);
        add_bullet(65,27);
        break;
    case 7:
        add_bullet(71,30);
        add_bullet(72,30);
        add_bullet(73,30);
        add_bullet(74,30);
        add_bullet(75,30);
        add_bullet(75,30);
        add_bullet(75,30);
        break;
    }
}

void player::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_K)
        if(this->bullet_tier)
            this->bullet_tier--;
    if(event->key() == Qt::Key_L)
        this->bullet_tier++;
}
