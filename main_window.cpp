#include "main_window.h"
#include "ui_main_window.h"
#include "game.h"
#include "consts.h"

#include <QApplication>
#include <QGraphicsView>
#include <QTimer>

game* game_0;

main_window::main_window(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::main_window)
{
  ui->setupUi(this);
}

main_window::~main_window()
{
  delete ui;
}

void main_window::on_pushButton_clicked()
{
  game_0 = new game();
  game_0->setCursor(Qt::BlankCursor);
  game_0->show();
}

void main_window::on_pushButton_2_clicked()
{

}
