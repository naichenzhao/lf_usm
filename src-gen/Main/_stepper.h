#ifndef _STEPPER_H
#define _STEPPER_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1615535645_H
#define TOP_LEVEL_PREAMBLE_1615535645_H
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
} _stepper_set_speed_0_t;
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
} _stepper_set_speed_1_t;
typedef struct {
    struct self_base_t base;
#line 40 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_stepper.h"
#line 41 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_stepper.h"
    _stepper_set_speed_0_t* _lf_set_speed_0;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_speed_0_width;
    // Default input (in case it does not get connected)
    _stepper_set_speed_0_t _lf_default__set_speed_0;
    _stepper_set_speed_1_t* _lf_set_speed_1;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_speed_1_width;
    // Default input (in case it does not get connected)
    _stepper_set_speed_1_t _lf_default__set_speed_1;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__set_speed_0;
    reaction_t* _lf__set_speed_0_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__set_speed_1;
    reaction_t* _lf__set_speed_1_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _stepper_self_t;
_stepper_self_t* new__stepper();
#endif // _STEPPER_H
