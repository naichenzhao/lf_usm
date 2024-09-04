#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/ROS_Interface/ROS_Interface.h"
#include "_ros_interface.h"
// *********** From the preamble, verbatim:
#line 27 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/ROS_Interface.lf"
extern UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

// Setup Rx and Tx buffers
static uint8_t rx_buffer[50];
static uint8_t tx_buffer[50];

int enc_data[6];
int16_t joint_data[6];
float scaled_joint_data[6];

// We have an inFlight indicator if the DMA is currently sending data
static volatile int inFlight = 0;

static float get_target(uint8_t* data) {
  float count = data[0] + (data[1]<<8) + (data[2]<<16) + (data[3]<<24) + (data[4]<<32);
  return count;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
  if (huart == &huart2) {
    inFlight = 0;
  }

}
#line 34 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_ros_interface.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _ros_interfacereaction_function_0(void* instance_args) {
    _ros_interface_self_t* self = (_ros_interface_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 56 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/ROS_Interface.lf"
    // Prep the send indicator
    tx_buffer[0] = 'e';
#line 46 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_ros_interface.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _ros_interfacereaction_function_1(void* instance_args) {
    _ros_interface_self_t* self = (_ros_interface_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _ros_interface_current_pos_t** current_pos = self->_lf_current_pos;
    int current_pos_width = self->_lf_current_pos_width; SUPPRESS_UNUSED_WARNING(current_pos_width);
    #line 61 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/ROS_Interface.lf"
    if (!inFlight) {
      enc_data[0] = (int)(current_pos[0]->value * 10000)/37;
      enc_data[1] = (int)(current_pos[1]->value * 10000)/20;
      enc_data[2] = (int)(current_pos[2]->value * 10000)/285;
      enc_data[3] = (int)(current_pos[3]->value * -10);
      enc_data[4] = (int)(current_pos[4]->value);
      enc_data[5] = (int)(current_pos[5]->value);
    }
#line 63 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_ros_interface.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _ros_interfacereaction_function_2(void* instance_args) {
    _ros_interface_self_t* self = (_ros_interface_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 72 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/ROS_Interface.lf"
    if (!inFlight) {
      inFlight = 1; // Indicate that we are currently sending data
      int num = sprintf(tx_buffer,"e%d,%d,%d,%d,%d,%d\r\n", enc_data[0], enc_data[1], enc_data[2], enc_data[3], enc_data[4], enc_data[5]);
      HAL_UART_Transmit_IT(&huart2, tx_buffer, num);
    }
#line 76 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_ros_interface.c"
}
#include "include/api/reaction_macros_undef.h"
_ros_interface_self_t* new__ros_interface() {
    _ros_interface_self_t* self = (_ros_interface_self_t*)lf_new_reactor(sizeof(_ros_interface_self_t));
    // Set the default source reactor pointer
    self->_lf_default__current_pos._base.source_reactor = (self_base_t*)self;
    // Set the default source reactor pointer
    self->_lf_default__sea_pos._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _ros_interfacereaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _ros_interfacereaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _ros_interfacereaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__trigger_send.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger_send.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_send_reactions[0] = &self->_lf__reaction_2;
    self->_lf__trigger_send.reactions = &self->_lf__trigger_send_reactions[0];
    self->_lf__trigger_send.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__trigger_send.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__trigger_send.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger_send.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_read.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger_read.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_read.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger_read.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__current_pos.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__current_pos.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__current_pos_reactions[0] = &self->_lf__reaction_1;
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
    self->_lf__sea_pos.tmplt.type.element_size = sizeof(float);
    return self;
}
