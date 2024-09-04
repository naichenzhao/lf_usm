#ifndef _USM_H
#define _USM_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_737085888_H
#define TOP_LEVEL_PREAMBLE_737085888_H
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
} _usm_set_speed_2_t;
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
} _usm_set_speed_3_t;
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
} _usm_set_speed_4_t;
typedef struct {
    struct self_base_t base;
#line 54 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_usm.h"
#line 55 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_usm.h"
    _usm_set_speed_2_t* _lf_set_speed_2;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_speed_2_width;
    // Default input (in case it does not get connected)
    _usm_set_speed_2_t _lf_default__set_speed_2;
    _usm_set_speed_3_t* _lf_set_speed_3;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_speed_3_width;
    // Default input (in case it does not get connected)
    _usm_set_speed_3_t _lf_default__set_speed_3;
    _usm_set_speed_4_t* _lf_set_speed_4;
    // width of -2 indicates that it is not a multiport.
    int _lf_set_speed_4_width;
    // Default input (in case it does not get connected)
    _usm_set_speed_4_t _lf_default__set_speed_4;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__set_speed_2;
    reaction_t* _lf__set_speed_2_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__set_speed_3;
    reaction_t* _lf__set_speed_3_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    trigger_t _lf__set_speed_4;
    reaction_t* _lf__set_speed_4_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _usm_self_t;
_usm_self_t* new__usm();
#endif // _USM_H
