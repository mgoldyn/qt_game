#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class QMediaPlayer;

class player : public QObject, public QGraphicsPixmapItem
{
protected:
    Q_OBJECT
    void keyPressEvent(QKeyEvent* event);
public:
    player();
public slots:
    void spawn();
private:
    QMediaPlayer* bullet_sound;
};
#endif // MYRECT_H
