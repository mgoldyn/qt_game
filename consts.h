#ifndef CONSTS_H
#define CONSTS_H
namespace consts
{
const unsigned int step_size      = 20;
const unsigned int enemy_step     = 16;
const unsigned int screen_width   = 1200;
const unsigned int screen_height  = 900;
const unsigned int player_width   = 100;
const unsigned int player_height  = 100;
const unsigned int player_wdh_ref = screen_width / 2 - player_width / 2;
const unsigned int player_hgt_ref = screen_height - player_height;
const unsigned int enemy0_width   = 100;
const unsigned int enemy0_height  = 100;
const unsigned int bullet_width   = 10;
const unsigned int bullet_height  = 25;

const bool direction_up   = true;
const bool direction_down = false;
}
#endif // CONSTS_H
