#include "game.h"
#include "consts.h"
#include "main_window.h"
#include "text_file.cpp"

#include <QApplication>
#include <QGraphicsView>
#include <QTimer>



int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    main_window gui_window;
    gui_window.show();
    check_file();





    return a.exec();
}
