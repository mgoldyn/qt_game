#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class QMediaPlayer;
class game;

class player : public QObject, public QGraphicsPixmapItem
{
protected:
    friend class game;
    Q_OBJECT
    game* game0;
    void keyPressEvent(QKeyEvent* event);

public:
    player(game* game0 = nullptr);
    void tier_up();

private:
    QMediaPlayer* bullet_sound;
    unsigned int bullet_tier;
    void add_bullet(const unsigned int tier,
                    const unsigned int step_size,
                    const QString image_dir);
    void add_bullets(      unsigned int first_case,
                     const unsigned int num_of_cases,
                     const unsigned int bullet_speed);
private slots:
    void make_bullets();
    void spawn();
};
#endif // MYRECT_H
