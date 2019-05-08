#include "game.h"
#include "enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

game::game()
{
    // create the scene
    enemy_counter = 0;
    score_0 = new text(nullptr, QString("Score:"), Qt::blue, 16);
    life_0  = new text(nullptr, QString("Life:"), Qt::red, 15);
    player_0 = new player(this);

    QGraphicsScene* scene = new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0, 0, consts::screen_width, consts::screen_height);
    setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(consts::screen_width, consts::screen_height);
    scene->addItem(player_0);
    scene->addItem(score_0);
    scene->addItem(life_0);

    //    spwan enemies and shoot bullets
    QTimer* timer = new QTimer();
    timer_0       = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player_0, SLOT(spawn()));
    QObject::connect(timer_0, SIGNAL(timeout()), player_0, SLOT(make_bullets()));

    timer->start(2000);

    //    background music
    //    QMediaPlayer* music = new QMediaPlayer();
    //    music->setMedia(QUrl("qrc:/sounds/ao_no_exorcism.mp3"));
    //    music->play();

    show();
}

void game::mouseMoveEvent(QMouseEvent* event)
{
    player_0->setPos(event->pos());
}

void game::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        player_0->make_bullets();
        timer_0->start(150);
    }
    if(event->button() == Qt::MouseButton::RightButton)
    {
        player_0->add_bullet(1, consts::step_size,":/images/kaczka2.png");
    }
}

void game::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
        timer_0->stop();
}
void player::spawn()
{
    if(game0->score_0->get_value() % 10== 0 && game0->score_0->get_value())
    {
        enemy* enemy_0 = new enemy(":/images/enemy_1_angry.png", 40, 0);
        scene()->addItem(enemy_0);
    }
    else if(game0->enemy_counter < 5)
    {
        enemy* enemy_0 = new enemy();
        scene()->addItem(enemy_0);
        game0->enemy_counter++;
    }
    else
    {
        game0->enemy_counter = 0;
    }
}
