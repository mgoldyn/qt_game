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

void player::add_bullet(const unsigned int tier         = 1,
                        const unsigned int bullet_speed = consts::bullet_step,
                        const QString image_dir         = ":/images/kaczka.png")
{
    bullet* bull = new bullet(image_dir, bullet_speed, tier);
    bull->set_attack_params(input_pack(this->x(), this->y(), bullet_sound));
    scene()->addItem(bull);
}

void player::add_bullets(      unsigned int in_case,
                         const unsigned int num_of_cases)
{
    unsigned int first_case = 10 * in_case + 1;
    //cases to generate bulelts
    for (unsigned int case_num = first_case; case_num < first_case + num_of_cases; case_num++)
    {
        add_bullet(case_num, consts::bullet_step);
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
        add_bullets(bullet_tier, 3);
        break;
    case 5:
        add_bullets(bullet_tier, 4);
        break;
    case 6:
        add_bullets(bullet_tier, 5);
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
