#ifndef _MAIN_MAIN_H
#define _MAIN_MAIN_H
#include "include/core/reactor.h"
#include "_motor_driver.h"
#include "_home.h"
#include "_qdec.h"
#ifndef TOP_LEVEL_PREAMBLE_935520971_H
#define TOP_LEVEL_PREAMBLE_935520971_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include <stdio.h>
#endif
typedef struct {
    struct self_base_t base;
#line 24 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.h"
    #line 65 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    int count;
#line 27 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.h"
    struct {
        _motor_driver_target_pos_t** target_pos;
        int target_pos_width;
        _motor_driver_target_sel_t** target_sel;
        int target_sel_width;
        _motor_driver_target_speed_t** target_speed;
        int target_speed_width;
    } _lf_motors;
    int _lf_motors_width;
    struct {
        _qdec_reset_qdec_t reset_qdec;
    } _lf_qdec;
    int _lf_qdec_width;
    struct {
        _home_motor_speed_t** motor_speed;
        int motor_speed_width;
        trigger_t motor_speed_trigger;
        reaction_t* motor_speed_reactions[1];
    } _lf_home;
    int _lf_home_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    reaction_t _lf__reaction_4;
    reaction_t _lf__reaction_5;
    trigger_t _lf__motor_update;
    reaction_t* _lf__motor_update_reactions[2];
    trigger_t _lf__switch_motor;
    reaction_t* _lf__switch_motor_reactions[1];
    trigger_t _lf__home_pulse;
    reaction_t* _lf__home_pulse_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[2];
} _main_main_main_self_t;
_main_main_main_self_t* new__main_main();
#endif // _MAIN_MAIN_H
