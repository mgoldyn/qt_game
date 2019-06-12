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
    unsigned int bullet_tier;

private:
    QMediaPlayer* bullet_sound;
    void add_bullet(const unsigned int tier,
                    const unsigned int step_size,
                    const QString image_dir);
    void add_bullets(unsigned int first_case,
                     const unsigned int num_of_cases);
private slots:
    void make_bullets();
    void spawn();
};
#endif // MYRECT_H
