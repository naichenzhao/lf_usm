#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/Main/Main.h"
#include "_main_main.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
extern UART_HandleTypeDef huart2;


// Target positions
// X: [0] - [37]
// Y: [0] - [21]
// Z: [0] - [-285]
// R: [-90] - [90]
float target_pos[6] =   {0, 0, 0, 0, 0, 0};
float target_speed[6] = {0, 0, 0, 0, 0, 0};
bool target_sel[6] =    {0, 0, 0, 0, 0, 0};

// We have 3 potential output LEDS:
// - PA5 - Onboard LED
// - PC14, PC15 - PCB LEDs
static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
#line 46 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_0(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 80 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    MX_GPIO_Init();
#line 57 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_1(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motor_driver_target_pos_t** target_pos;
    int target_pos_width;
    
    } motors;
    motors.target_pos = self->_lf_motors.target_pos;
    motors.target_pos_width = self->_lf_motors.target_pos_width;
    #line 86 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    for (int i=0; i<6; i++) {
    lf_set(motors.target_pos[i], target_pos[i]);
        }
#line 74 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_2(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct qdec {
        _qdec_reset_qdec_t* reset_qdec;
    
    } qdec;
    qdec.reset_qdec = &(self->_lf_qdec.reset_qdec);
    reactor_mode_t* RUN = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_RUN_change_type = reset_transition;
    #line 97 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    // If all the speeds are set to zero, we assume we have corrctly homed
    bool all_homed = true;
    for(int i=0; i<6; i++) {
      all_homed = all_homed && (target_speed[i] == 0);
    }
    
    // If homed, we transition to the run state
    if (all_homed) {
      for(int i=0; i<6; i++) {
        target_pos[i] = 0;
      }
      lf_set(qdec.reset_qdec, true);
      lf_set_mode(RUN);
      printf("--- Finished Homing ---\r\n");
    }
#line 103 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_3(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct home {
        _home_motor_speed_t** motor_speed;
    int motor_speed_width;
    
    } home;
    home.motor_speed = self->_lf_home.motor_speed;
    home.motor_speed_width = self->_lf_home.motor_speed_width;
    #line 115 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    for(int i=0; i<6; i++) {
      target_speed[i] = home.motor_speed[i]->value;
    }
#line 120 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_4(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motor_driver_target_sel_t** target_sel;
    int target_sel_width;
    _motor_driver_target_speed_t** target_speed;
    int target_speed_width;
    
    } motors;
    motors.target_sel = self->_lf_motors.target_sel;
    motors.target_sel_width = self->_lf_motors.target_sel_width;
    motors.target_speed = self->_lf_motors.target_speed;
    motors.target_speed_width = self->_lf_motors.target_speed_width;
    #line 121 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    for (int i=0; i<6; i++) {
      lf_set(motors.target_sel[i], 0);
      lf_set(motors.target_speed[i], target_speed[i]);
    }
#line 142 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _main_mainreaction_function_5(void* instance_args) {
    _main_main_main_self_t* self = (_main_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motor_driver_target_sel_t** target_sel;
    int target_sel_width;
    _motor_driver_target_speed_t** target_speed;
    int target_speed_width;
    
    } motors;
    motors.target_sel = self->_lf_motors.target_sel;
    motors.target_sel_width = self->_lf_motors.target_sel_width;
    motors.target_speed = self->_lf_motors.target_speed;
    motors.target_speed_width = self->_lf_motors.target_speed_width;
    #line 132 "/Users/naichenzhao/Desktop/BML/lf_usm/src/Main.lf"
    printf("switch state: %d\r\n", self->count);
    lf_set(motors.target_speed[2], 0);
    lf_set(motors.target_speed[3], 0);
    lf_set(motors.target_speed[4], 0);
    lf_set(motors.target_speed[5], 0);
    lf_set(motors.target_speed[1], 0);
    if (self->count == 0) {
      self->count = 1;
      // lf_set(motors.target_pos[0], 50);
      lf_set(motors.target_speed[0], 0);
    } else {
      self->count = 0;
      // lf_set(motors.target_pos[0], 0);
      lf_set(motors.target_speed[0], 50);
    }
    
    
    for (int i=1; i<6; i++) {
      lf_set(motors.target_sel[i], 0);
    }
    lf_set(motors.target_sel[0], 1);
#line 181 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_main_main.c"
}
#include "include/api/reaction_macros_undef.h"
_main_main_main_self_t* new__main_main() {
    _main_main_main_self_t* self = (_main_main_main_self_t*)lf_new_reactor(sizeof(_main_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motors_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_qdec_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_home_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_home.motor_speed_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_home.motor_speed_reactions[0] = &self->_lf__reaction_3;
    self->_lf_home.motor_speed_trigger.reactions = self->_lf_home.motor_speed_reactions;
    self->_lf_home.motor_speed_trigger.last_tag = NEVER_TAG;
    self->_lf_home.motor_speed_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_home.motor_speed_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _main_mainreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _main_mainreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _main_mainreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = &self->_lf__modes[0];
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _main_mainreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    self->_lf__reaction_4.number = 4;
    self->_lf__reaction_4.function = _main_mainreaction_function_4;
    self->_lf__reaction_4.self = self;
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    self->_lf__reaction_4.STP_handler = NULL;
    self->_lf__reaction_4.name = "?";
    self->_lf__reaction_4.mode = &self->_lf__modes[0];
    self->_lf__reaction_5.number = 5;
    self->_lf__reaction_5.function = _main_mainreaction_function_5;
    self->_lf__reaction_5.self = self;
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    self->_lf__reaction_5.STP_handler = NULL;
    self->_lf__reaction_5.name = "?";
    self->_lf__reaction_5.mode = &self->_lf__modes[1];
    self->_lf__motor_update.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__motor_update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__motor_update_reactions[0] = &self->_lf__reaction_1;
    self->_lf__motor_update_reactions[1] = &self->_lf__reaction_4;
    self->_lf__motor_update.reactions = &self->_lf__motor_update_reactions[0];
    self->_lf__motor_update.number_of_reactions = 2;
    #ifdef FEDERATED
    self->_lf__motor_update.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__motor_update.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__motor_update.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__switch_motor.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__switch_motor.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__switch_motor_reactions[0] = &self->_lf__reaction_5;
    self->_lf__switch_motor.reactions = &self->_lf__switch_motor_reactions[0];
    self->_lf__switch_motor.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__switch_motor.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__switch_motor.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__switch_motor.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__home_pulse.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__home_pulse.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__home_pulse_reactions[0] = &self->_lf__reaction_2;
    self->_lf__home_pulse.reactions = &self->_lf__home_pulse_reactions[0];
    self->_lf__home_pulse.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__home_pulse.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__home_pulse.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__home_pulse.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[0].name = "HOME";
    self->_lf__modes[0].deactivation_time = 0;
    self->_lf__modes[0].flags = 0;
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    self->_lf__modes[1].name = "RUN";
    self->_lf__modes[1].deactivation_time = 0;
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}
