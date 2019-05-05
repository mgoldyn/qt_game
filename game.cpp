#include "game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

game::game(){
    // create the scene
    QGraphicsScene* scene = new QGraphicsScene();

    setScene(scene);
    scene->setSceneRect(0, 0, consts::screen_width, consts::screen_height);
    setBackgroundBrush(QBrush(Qt::green , Qt::SolidPattern));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(consts::screen_width, consts::screen_height);

    player* player_0 = new player();
    player_0->setPixmap(QPixmap(":/images/gracz.png"));
    player_0->setPos(consts::player_wdh_ref,
                     consts::player_hgt_ref);
    player_0->setFlag(QGraphicsItem::ItemIsFocusable);
    player_0->setFocus();
    score_0 = new text(nullptr, QString("Score:"), Qt::blue, 16);
    life_0  = new text(nullptr, QString("Life:"),  Qt::red,  15);
    scene->addItem(player_0);
    scene->addItem(score_0);
    scene->addItem(life_0);

    //    spwan enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player_0, SLOT(spawn()));
    timer->start(2000);

//    background music
//    QMediaPlayer* music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sounds/ao_no_exorcism.mp3"));
//    music->play();

    show();
}
