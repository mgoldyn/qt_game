#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class QMediaPlayer;

class player : public QObject, public QGraphicsPixmapItem
{
protected:
    friend class game;
    Q_OBJECT
    void keyPressEvent(QKeyEvent* event);
public:
    player();
private:
    QMediaPlayer* bullet_sound;
    unsigned int bullet_tier;
    void add_bullet(const unsigned int tier, const unsigned int step_size, const QString image_dir);
private slots:
    void spawn();
    void make_bullets();
};
#endif // MYRECT_H
