#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class QMediaPlayer;

class player : public QObject, public QGraphicsRectItem
{
protected:
    Q_OBJECT
    void keyPressEvent(QKeyEvent* event);
public:
    player();
public slots:
    void spawn();
private:
    QMediaPlayer* bulletsound;
};
#endif // MYRECT_H
