#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/Home/Home.h"
#include "_home.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _homereaction_function_0(void* instance_args) {
    _home_self_t* self = (_home_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct homing_switches {
        _switches_read_t** read;
    int read_width;
    
    } homing_switches;
    _home_current_pos_t** current_pos = self->_lf_current_pos;
    int current_pos_width = self->_lf_current_pos_width; SUPPRESS_UNUSED_WARNING(current_pos_width);
    _home_sea_pos_t** sea_pos = self->_lf_sea_pos;
    int sea_pos_width = self->_lf_sea_pos_width; SUPPRESS_UNUSED_WARNING(sea_pos_width);
    homing_switches.read = self->_lf_homing_switches.read;
    homing_switches.read_width = self->_lf_homing_switches.read_width;
    int motor_speed_width = self->_lf_motor_speed_width; SUPPRESS_UNUSED_WARNING(motor_speed_width);
    _home_motor_speed_t** motor_speed = self->_lf_motor_speed_pointers;
    #line 40 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Home.lf"
    float SEA_LIM_0 = 0.08;
    float SEA_LIM_1 = 0.035;
    float DIFF_LIM = 0.1;
    
    if ( self->update_cnt > 4) {
      for (int i=0; i<6; i++) {
        self->pos_diff[i] = current_pos[i]->value - self->last_pos[i];
        self->last_pos[i] = current_pos[i]->value;
      }
       self->update_cnt = 0;
    } else {
       self->update_cnt ++;
    }
    
    
    // Check home condidions
    if(self->is_home[0] != 0) {
      if (self->is_home[0] == 1){
        self->diffzero_cnt[0] = (sea_pos[0]->value > SEA_LIM_0)?self->diffzero_cnt[0]+1:0;
        self->is_home[0] = (self->diffzero_cnt[0] >= 30) ? 2:1;
      } else if (self->is_home[0] == 2){
        self->home_speed[0] = 5;
        self->is_home[0] = (sea_pos[0]->value > 0) ? 2:3;
      } else {
        self->home_speed[0] = -5;
        self->is_home[0] = (sea_pos[0]->value < 0) ? 3:0;
      }
    }
    
    if(self->is_home[1] != 0) {
      if (self->is_home[1] == 1){
        self->diffzero_cnt[1] = (sea_pos[1]->value > SEA_LIM_1)?self->diffzero_cnt[1]+1:0;
        self->is_home[1] = (self->diffzero_cnt[1] >= 10) ? 2:1;
      } else if (self->is_home[1] == 2){
        self->home_speed[1] = 7;
        self->is_home[1] = (sea_pos[1]->value > 0) ? 2:3;
      } else {
        self->home_speed[1] = -7;
        self->is_home[1] = (sea_pos[1]->value < 0) ? 3:0;
      }
    }
    
    if(self->is_home[2] != 0) {
      if(self->pos_diff[2] < DIFF_LIM) {
        self->diffzero_cnt[2]++;
        self->is_home[2] = self->diffzero_cnt[2] <=60;
      } else {
        self->diffzero_cnt[2] = 0;
      }
    }
    
    if(self->is_home[3] != 0) {
      if (current_pos[3]->value > 0) {
        self->home_speed[3] = 20;
        self->diffzero_cnt[3] = 0;
      }else if (current_pos[3]->value < -1) {
          self->home_speed[3] = -20;
          self->diffzero_cnt[3] = 0;
      } else {
        self->home_speed[3] = 0;
        self->diffzero_cnt[3]++;
        self->is_home[3] = self->diffzero_cnt[3] <= 20;
      }
    
    }
    
    if(self->is_home[4] != 0) {
      if (self->is_home[4] == 1) {
        self->is_home[4] = (homing_switches.read[0]->value)? 2:1;
        self->home_speed[4] = -30;
        self->home_speed[5] = -30;
      } else if(self->is_home[4] == 2) {
        self->is_home[4] = (homing_switches.read[1]->value)? 3:2;
        self->home_speed[4] = -30;
        self->home_speed[5] = 30;
      } else if(self->is_home[4] == 3){
        self->is_home[4] = (homing_switches.read[1]->value)? 3:0;
        self->is_home[5] = (homing_switches.read[1]->value)? 3:0;
        self->home_speed[4] = 30;
        self->home_speed[5] = -30;
      }
    }
    
    // printf("state: %d\n", (int) self->is_home[4]);
    
    self->last_sea[0] = sea_pos[0]->value;
    self->last_sea[1] = sea_pos[1]->value;
    
    // Set motor speeds
    for (int i=0; i<6; i++) {
      if (self->is_home[i] != 0) {
        lf_set(motor_speed[i], self->home_speed[i]); // If we want to home
      }else {
        lf_set(motor_speed[i], 0);                   // If we are already homed
      }
    }
#line 121 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_home.c"
}
#include "include/api/reaction_macros_undef.h"
_home_self_t* new__home() {
    _home_self_t* self = (_home_self_t*)lf_new_reactor(sizeof(_home_self_t));
    // Set the default source reactor pointer
    self->_lf_default__current_pos._base.source_reactor = (self_base_t*)self;
    // Set the default source reactor pointer
    self->_lf_default__sea_pos._base.source_reactor = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_homing_switches_width = -2;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf_homing_switches.read_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf_homing_switches.read_reactions[0] = &self->_lf__reaction_0;
    self->_lf_homing_switches.read_trigger.reactions = self->_lf_homing_switches.read_reactions;
    self->_lf_homing_switches.read_trigger.last_tag = NEVER_TAG;
    self->_lf_homing_switches.read_trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf_homing_switches.read_trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _homereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
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
    return self;
}
