#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/FFB/FFB_Controller.h"
#include "_ffb_controller.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _ffb_controllerreaction_function_0(void* instance_args) {
    _ffb_controller_self_t* self = (_ffb_controller_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _ffb_controller_target_pos_t* target_pos = self->_lf_target_pos;
    int target_pos_width = self->_lf_target_pos_width; SUPPRESS_UNUSED_WARNING(target_pos_width);
    _ffb_controller_current_pos_t* current_pos = self->_lf_current_pos;
    int current_pos_width = self->_lf_current_pos_width; SUPPRESS_UNUSED_WARNING(current_pos_width);
    _ffb_controller_sea_pos_t* sea_pos = self->_lf_sea_pos;
    int sea_pos_width = self->_lf_sea_pos_width; SUPPRESS_UNUSED_WARNING(sea_pos_width);
    _ffb_controller_out_t* out = &self->_lf_out;
    #line 28 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Joint_Controllers/FFB.lf"
    float UPPER_LIM = 0.02;
    float pid_out;
    
    float error_p = sea_pos->value;
    float sea_diff = (sea_pos->value - self->last_sea);
    self->last_sea = sea_pos->value;
    
    bool pos_flag = (error_p > UPPER_LIM || error_p < -UPPER_LIM);
    bool change_flag = (sea_diff > self->D_LIM || sea_diff < -self->D_LIM);
    // FSM for control state.
    // 0: We are in the idle state
    // 1: We are moving
    if(self->fsm_state) {
      pid_out = self->Ks * error_p;
      self->fsm_state = (error_p > self->SLIM || error_p < -self->SLIM);
    } else {
      pid_out = 0;
      self->fsm_state = pos_flag || change_flag;
    }
    
    pid_out = pid_out < -100? -100: pid_out;
    pid_out = pid_out > 100? 100: pid_out;
    
    // printf("error: %d, out: %d\r\n", (int)(error_p * 100), (int)pid_out);
    lf_set(out, pid_out);
#line 44 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_ffb_controller.c"
}
#include "include/api/reaction_macros_undef.h"
_ffb_controller_self_t* new__ffb_controller() {
    _ffb_controller_self_t* self = (_ffb_controller_self_t*)lf_new_reactor(sizeof(_ffb_controller_self_t));
    // Set input by default to an always absent default input.
    self->_lf_current_pos = &self->_lf_default__current_pos;
    // Set the default source reactor pointer
    self->_lf_default__current_pos._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_sea_pos = &self->_lf_default__sea_pos;
    // Set the default source reactor pointer
    self->_lf_default__sea_pos._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_target_pos = &self->_lf_default__target_pos;
    // Set the default source reactor pointer
    self->_lf_default__target_pos._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _ffb_controllerreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__current_pos.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__current_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__current_pos_reactions[0] = &self->_lf__reaction_0;
    self->_lf__current_pos.reactions = &self->_lf__current_pos_reactions[0];
    self->_lf__current_pos.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__current_pos.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__current_pos.tmplt.type.element_size = sizeof(float);
    self->_lf__sea_pos.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__sea_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__sea_pos_reactions[0] = &self->_lf__reaction_0;
    self->_lf__sea_pos.reactions = &self->_lf__sea_pos_reactions[0];
    self->_lf__sea_pos.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__sea_pos.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__sea_pos.tmplt.type.element_size = sizeof(float);
    self->_lf__target_pos.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__target_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__target_pos_reactions[0] = &self->_lf__reaction_0;
    self->_lf__target_pos.reactions = &self->_lf__target_pos_reactions[0];
    self->_lf__target_pos.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__target_pos.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__target_pos.tmplt.type.element_size = sizeof(float);
    return self;
}
