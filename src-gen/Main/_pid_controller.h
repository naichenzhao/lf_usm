#ifndef _PID_CONTROLLER_H
#define _PID_CONTROLLER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_655059806_H
#define TOP_LEVEL_PREAMBLE_655059806_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_current_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_sea_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_target_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _pid_controller_out_t;
typedef struct {
    struct self_base_t base;
    #line 14 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float Kp;
    #line 14 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float Ki;
    #line 14 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float Kd;
#line 74 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_pid_controller.h"
    #line 20 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float last_pos;
    #line 21 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    interval_t prev_time;
    #line 22 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float Kw;
    #line 24 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/PID.lf"
    float error_i;
#line 83 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_pid_controller.h"
    _pid_controller_current_pos_t* _lf_current_pos;
    // width of -2 indicates that it is not a multiport.
    int _lf_current_pos_width;
    // Default input (in case it does not get connected)
    _pid_controller_current_pos_t _lf_default__current_pos;
    _pid_controller_sea_pos_t* _lf_sea_pos;
    // width of -2 indicates that it is not a multiport.
    int _lf_sea_pos_width;
    // Default input (in case it does not get connected)
    _pid_controller_sea_pos_t _lf_default__sea_pos;
    _pid_controller_target_pos_t* _lf_target_pos;
    // width of -2 indicates that it is not a multiport.
    int _lf_target_pos_width;
    // Default input (in case it does not get connected)
    _pid_controller_target_pos_t _lf_default__target_pos;
    _pid_controller_out_t _lf_out;
    int _lf_out_width;
    reaction_t _lf__reaction_0;
    trigger_t _lf__current_pos;
    reaction_t* _lf__current_pos_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__sea_pos;
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__target_pos;
    reaction_t* _lf__target_pos_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _pid_controller_self_t;
_pid_controller_self_t* new__pid_controller();
#endif // _PID_CONTROLLER_H
