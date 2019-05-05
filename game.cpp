#include "game.h"
#include "enemy.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

void game::mouseMoveEvent(QMouseEvent *event)
{
    player_0->setPos(event->pos());
}

void game::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        player_0->make_bullets();
        timer_0->start(150);
    }

}

void game::mouseReleaseEvent(QMouseEvent *event)
{
    timer_0->stop();
}

game::game(){
    // create the scene
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView::unsetCursor();
    setScene(scene);
    scene->setSceneRect(0, 0, consts::screen_width, consts::screen_height);
    setBackgroundBrush(QBrush(Qt::green , Qt::SolidPattern));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(consts::screen_width, consts::screen_height);
    player_0 = new player();
    player_0->setPixmap(QPixmap(":/images/gracz.png"));
    player_0->setFlag(QGraphicsItem::ItemIsFocusable);
    player_0->setFocus();
    score_0 = new text(nullptr, QString("Score:"), Qt::blue, 16);
    life_0  = new text(nullptr, QString("Life:"),  Qt::red,  15);
    scene->addItem(player_0);
    scene->addItem(score_0);
    scene->addItem(life_0);

    //    spwan enemies
    QTimer* timer = new QTimer();
    timer_0 = new QTimer();
    QObject::connect(timer,   SIGNAL(timeout()), player_0, SLOT(spawn()));
    QObject::connect(this->timer_0, SIGNAL(timeout()), player_0, SLOT(make_bullets()));

    timer->start(2000);

//    background music
//    QMediaPlayer* music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sounds/ao_no_exorcism.mp3"));
//    music->play();

    show();
}
