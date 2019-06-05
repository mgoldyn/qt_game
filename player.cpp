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

void player::add_bullet(const unsigned int tier         = 1,
                        const unsigned int bullet_speed = consts::bullet_step,
                        const QString image_dir         = ":/images/kaczka.png")
{
    bullet* bull = new bullet(image_dir, bullet_speed, tier);
    bull->set_attack_params(input_pack(this->x(), this->y(), bullet_sound));
    scene()->addItem(bull);
}

void player::add_bullets(      unsigned int first_case,
                         const unsigned int num_of_cases,
                         const unsigned int bullet_speed = consts::bullet::speed)
{
    first_case = 10 * first_case + 1;
    for (unsigned int case_num = first_case; case_num <= first_case + num_of_cases; case_num++)
    {
        add_bullet(case_num, bullet_speed);
    }
}

void player::make_bullets()
{
    switch(bullet_tier)
    {
    case 1:
    {
        add_bullet(bullet_tier);
        break;
    }
    case 2:
    {
        add_bullets(bullet_tier, bullet_tier);
        break;
    }
    case 3:
    {
        add_bullets(bullet_tier, bullet_tier);
        break;
    }
    case 4:
        add_bullets(bullet_tier, bullet_tier);
        break;
    case 5:
        add_bullets(bullet_tier, bullet_tier - 1);
        break;
    case 6:
        add_bullets(bullet_tier, bullet_tier - 1);
        break;
    case 7:
        add_bullets(bullet_tier, bullet_tier);
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
