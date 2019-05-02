#include "game.h"
#include "consts.h"

#include <QApplication>
#include <QGraphicsView>
#include <QTimer>

game* game_0;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    game_0 = new game();
    game_0->show();


    return a.exec();
}
