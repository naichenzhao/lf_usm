#ifndef _main_main_H
#define _main_main_H
#ifndef _MAIN_MAIN_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_935520971_H
#define TOP_LEVEL_PREAMBLE_935520971_H
/*Correspondence: Range: [(9, 2), (10, 18)) -> Range: [(0, 0), (1, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Encoder.lf)*/#include "stm32f4xx_hal.h"
#include <stdio.h>
/*Correspondence: Range: [(16, 2), (18, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Driver.lf)*/#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
/*Correspondence: Range: [(14, 2), (16, 26)) -> Range: [(0, 0), (2, 26)) (verbatim=true; src=/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf)*/#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
/*Correspondence: Range: [(11, 2), (13, 18)) -> Range: [(0, 0), (2, 18)) (verbatim=true; src=/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Home.lf)*/#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
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
typedef struct main_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int count;
    int end[0]; // placeholder; MSVC does not compile empty structs
} main_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} qdec_reset_qdec_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} qdec_qdec_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} qdec_sea_out_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} motor_driver_target_sel_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motor_driver_target_speed_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motor_driver_target_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motor_driver_qdec_current_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motor_driver_qdec_sea_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} home_current_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} home_sea_pos_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} home_motor_speed_t;
#endif
#endif
