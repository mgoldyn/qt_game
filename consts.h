#ifndef CONSTS_H
#define CONSTS_H

#include <tuple>

#define uint32 unsigned int
#define UINT_TUPLE std::tuple<uint32, uint32>

namespace consts
{
const uint32 step_size      = 1;
const uint32 enemy_step     = 6;
const uint32 screen_width   = 1200;
const uint32 screen_height  = 900;
const uint32 player_width   = 100;
const uint32 player_height  = 100;
const uint32 player_wdh_ref = screen_width / 2 - player_width / 2;
const uint32 player_hgt_ref = screen_height - player_height;
const uint32 enemy0_width   = 100;
const uint32 enemy0_height  = 100;
const uint32 bullet_width   = 10;
const uint32 bullet_height  = 25;
const uint32 bullet_step    = 8;

const bool direction_up   = true;
const bool direction_down = false;

namespace bullet
{
    const uint32 speed = 8;
    const uint32 max_tier = 6;
    const uint32 multiplier[6] = {0, 1, 2, 3, 4, 5};
    const uint32 divisor[3]    = {5, 6, 7};
    const UINT_TUPLE t1_center_pos (multiplier[2], divisor[0]);
    const UINT_TUPLE t2_left_pos   (multiplier[1], divisor[0]);
    const UINT_TUPLE t2_right_pos  (multiplier[3], divisor[0]);
    const UINT_TUPLE t3_left_pos   (multiplier[1], divisor[0]);
    const UINT_TUPLE t3_center_pos (multiplier[2], divisor[0]);
    const UINT_TUPLE t3_right_pos  (multiplier[3], divisor[0]);
    const UINT_TUPLE t4_left_pos   (multiplier[1], divisor[0]);
    const UINT_TUPLE t4_center_pos (multiplier[2], divisor[0]);
    const UINT_TUPLE t4_right_pos  (multiplier[3], divisor[0]);
    const UINT_TUPLE t5_l_left_pos (multiplier[1], divisor[1]);
    const UINT_TUPLE t5_left_pos   (multiplier[2], divisor[1]);
    const UINT_TUPLE t5_right_pos  (multiplier[3], divisor[1]);
    const UINT_TUPLE t5_r_right_pos(multiplier[4], divisor[1]);
    const UINT_TUPLE t6_l_left_pos (multiplier[1], divisor[2]);
    const UINT_TUPLE t6_left_pos   (multiplier[2], divisor[2]);
    const UINT_TUPLE t6_center_pos (multiplier[3], divisor[2]);
    const UINT_TUPLE t6_right_pos  (multiplier[4], divisor[2]);
    const UINT_TUPLE t6_r_right_pos(multiplier[5], divisor[2]);

}
}
#endif // CONSTS_H
