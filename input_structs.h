#ifndef INPUT_STRUCTS_H
#define INPUT_STRUCTS_H

#include <QMediaPlayer>

struct input_pack
{
    double  player_x;
    double  player_y;
    QMediaPlayer* sound;

    input_pack(double player_x = 0,
               double player_y = 0,
               QMediaPlayer* sound = nullptr)
    {
        this->player_x = player_x;
        this->player_y = player_y;
        this->sound    = sound;
    }
};

#endif // INPUT_STRUCTS_H
