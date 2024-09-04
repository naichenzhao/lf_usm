#ifndef _MOTOR_DRIVER_H
#define _MOTOR_DRIVER_H
#include "include/core/reactor.h"
#include "_stepper.h"
#include "_usm.h"
#include "_sea_controllery.h"
#include "_pid_controller.h"
#include "_sea_controllerx.h"
#ifndef TOP_LEVEL_PREAMBLE_1241897134_H
#define TOP_LEVEL_PREAMBLE_1241897134_H
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32_startup.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _motor_driver_target_sel_t;
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
} _motor_driver_target_speed_t;
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
} _motor_driver_target_pos_t;
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
} _motor_driver_qdec_current_t;
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
} _motor_driver_qdec_sea_t;
typedef struct {
    struct self_base_t base;
    #line 23 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Driver.lf"
    interval_t refresh_period;
#line 100 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_motor_driver.h"
    #line 31 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Driver.lf"
    bool* sel;
    #line 32 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Driver.lf"
    float* speed_spc;
    #line 33 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Driver.lf"
    float* speed_posc;
#line 107 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_motor_driver.h"
    // Multiport input array will be malloc'd later.
    _motor_driver_target_sel_t** _lf_target_sel;
    int _lf_target_sel_width;
    // Default input (in case it does not get connected)
    _motor_driver_target_sel_t _lf_default__target_sel;
    // Struct to support efficiently reading sparse inputs.
    lf_sparse_io_record_t* _lf_target_sel__sparse;
    // Multiport input array will be malloc'd later.
    _motor_driver_target_speed_t** _lf_target_speed;
    int _lf_target_speed_width;
    // Default input (in case it does not get connected)
    _motor_driver_target_speed_t _lf_default__target_speed;
    // Struct to support efficiently reading sparse inputs.
    lf_sparse_io_record_t* _lf_target_speed__sparse;
    // Multiport input array will be malloc'd later.
    _motor_driver_target_pos_t** _lf_target_pos;
    int _lf_target_pos_width;
    // Default input (in case it does not get connected)
    _motor_driver_target_pos_t _lf_default__target_pos;
    // Struct to support efficiently reading sparse inputs.
    lf_sparse_io_record_t* _lf_target_pos__sparse;
    // Multiport input array will be malloc'd later.
    _motor_driver_qdec_current_t** _lf_qdec_current;
    int _lf_qdec_current_width;
    // Default input (in case it does not get connected)
    _motor_driver_qdec_current_t _lf_default__qdec_current;
    // Struct to support efficiently reading sparse inputs.
    lf_sparse_io_record_t* _lf_qdec_current__sparse;
    // Multiport input array will be malloc'd later.
    _motor_driver_qdec_sea_t** _lf_qdec_sea;
    int _lf_qdec_sea_width;
    // Default input (in case it does not get connected)
    _motor_driver_qdec_sea_t _lf_default__qdec_sea;
    // Struct to support efficiently reading sparse inputs.
    lf_sparse_io_record_t* _lf_qdec_sea__sparse;
    struct {
        _sea_controllerx_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_x;
    int _lf_control_x_width;
    struct {
        _sea_controllery_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_y;
    int _lf_control_y_width;
    struct {
        _pid_controller_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_z;
    int _lf_control_z_width;
    struct {
        _pid_controller_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_r;
    int _lf_control_r_width;
    struct {
        _pid_controller_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_a1;
    int _lf_control_a1_width;
    struct {
        _pid_controller_out_t* out;
        trigger_t out_trigger;
        reaction_t* out_reactions[1];
    } _lf_control_a2;
    int _lf_control_a2_width;
    struct {
        _stepper_set_speed_0_t set_speed_0;
        _stepper_set_speed_1_t set_speed_1;
    } _lf_stepper;
    int _lf_stepper_width;
    struct {
        _usm_set_speed_2_t set_speed_2;
        _usm_set_speed_3_t set_speed_3;
        _usm_set_speed_4_t set_speed_4;
    } _lf_usm;
    int _lf_usm_width;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__trigger;
    reaction_t* _lf__trigger_reactions[1];
    trigger_t _lf__target_sel;
    reaction_t* _lf__target_sel_reactions[1];
    #ifdef FEDERATED
    trigger_t* _lf__target_sel_network_port_status;
    
    #endif // FEDERATED
    trigger_t _lf__target_speed;
    reaction_t* _lf__target_speed_reactions[1];
    #ifdef FEDERATED
    trigger_t* _lf__target_speed_network_port_status;
    
    #endif // FEDERATED
    trigger_t _lf__target_pos;
    #ifdef FEDERATED
    trigger_t* _lf__target_pos_network_port_status;
    
    #endif // FEDERATED
    trigger_t _lf__qdec_current;
    #ifdef FEDERATED
    trigger_t* _lf__qdec_current_network_port_status;
    
    #endif // FEDERATED
    trigger_t _lf__qdec_sea;
    #ifdef FEDERATED
    trigger_t* _lf__qdec_sea_network_port_status;
    
    #endif // FEDERATED
} _motor_driver_self_t;
_motor_driver_self_t* new__motor_driver();
#endif // _MOTOR_DRIVER_H
