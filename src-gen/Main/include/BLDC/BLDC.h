#ifndef _bldc_H
#define _bldc_H
#ifndef _BLDC_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_569959775_H
#define TOP_LEVEL_PREAMBLE_569959775_H
/*Correspondence: Range: [(9, 2), (10, 18)) -> Range: [(0, 0), (1, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/BLDC.lf)*/#include "stm32f4xx_hal.h"
#include <stdio.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct bldc_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    float* speeds;
    int end[0]; // placeholder; MSVC does not compile empty structs
} bldc_self_t;
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
} bldc_set_speed_0_t;
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
} bldc_set_speed_1_t;
#endif
#endif
