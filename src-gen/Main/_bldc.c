#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/BLDC/BLDC.h"
#include "_bldc.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/BLDC.lf"
UART_HandleTypeDef huart4;
UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

uint8_t mode_torque[4] = {'c', ' ', '0', ' '};
uint8_t mode_end[1] = {'\n'};

uint8_t data_buffer[11] = "c 0 0.0000\n";
uint8_t zero_buffer[11] = "c 0 0.0000\n";

uint8_t clear_errors[3]= {'s', 'c', '\n'};
uint8_t state_control[26]= "w axis0.requested_state 8\n";

static void MX_USART1_UART_Init(void){
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK) {
    Error_Handler();
  }
}

static void MX_UART4_Init(void) {
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 115200;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK){
    Error_Handler();
  }
}
#line 48 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_bldc.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _bldcreaction_function_0(void* instance_args) {
    _bldc_self_t* self = (_bldc_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 66 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/BLDC.lf"
    MX_USART1_UART_Init();
    MX_UART4_Init();
    
    HAL_UART_Transmit(&huart1, clear_errors, 3, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, state_control, 26, HAL_MAX_DELAY);
    
    HAL_UART_Transmit(&huart4, clear_errors, 3, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart4, state_control, 25, HAL_MAX_DELAY);
    
    HAL_Delay(300);
    HAL_UART_Transmit(&huart1, clear_errors, 3, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart4, clear_errors, 3, HAL_MAX_DELAY);
#line 70 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_bldc.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _bldcreaction_function_1(void* instance_args) {
    _bldc_self_t* self = (_bldc_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _bldc_set_speed_0_t* set_speed_0 = self->_lf_set_speed_0;
    int set_speed_0_width = self->_lf_set_speed_0_width; SUPPRESS_UNUSED_WARNING(set_speed_0_width);
    _bldc_set_speed_1_t* set_speed_1 = self->_lf_set_speed_1;
    int set_speed_1_width = self->_lf_set_speed_1_width; SUPPRESS_UNUSED_WARNING(set_speed_1_width);
    #line 81 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/BLDC.lf"
    self->speeds[0] = -((0.1 * set_speed_0->value)/100);
    self->speeds[1] = ((0.1 * set_speed_1->value)/100);
#line 83 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_bldc.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _bldcreaction_function_2(void* instance_args) {
    _bldc_self_t* self = (_bldc_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 86 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/BLDC.lf"
    // HAL_UART_Transmit(&huart1, clear_errors, 3, HAL_MAX_DELAY);
    // HAL_UART_Transmit(&huart4, clear_errors, 3, HAL_MAX_DELAY);
    
    if((self->speeds[0] < 0.0001 && self->speeds[0] > -0.0001) || !HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)) {
      HAL_UART_Transmit(&huart1,  zero_buffer, 11, HAL_MAX_DELAY);
      // HAL_UART_Transmit_IT(&huart1,  zero_buffer, 11);
    } else {
      gcvt(self->speeds[0], 6, data_buffer+4);
      data_buffer[10] = '\n';
      HAL_UART_Transmit(&huart1,  data_buffer, 11, HAL_MAX_DELAY);
      // HAL_UART_Transmit_IT(&huart1,  data_buffer, 11);
    }
    
    if((self->speeds[1] < 0.0001 && self->speeds[1] > -0.0001) || !HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)) {
      HAL_UART_Transmit(&huart4,  zero_buffer, 11, HAL_MAX_DELAY);
      // HAL_UART_Transmit_IT(&huart4,  zero_buffer, 11);
    } else {
      gcvt(self->speeds[1], 6, data_buffer+4);
      data_buffer[10] = '\n';
      HAL_UART_Transmit(&huart4,  data_buffer, 11, HAL_MAX_DELAY);
      // HAL_UART_Transmit_IT(&huart4,  data_buffer, 11);
    }
#line 113 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_bldc.c"
}
#include "include/api/reaction_macros_undef.h"
_bldc_self_t* new__bldc() {
    _bldc_self_t* self = (_bldc_self_t*)lf_new_reactor(sizeof(_bldc_self_t));
    // Set input by default to an always absent default input.
    self->_lf_set_speed_0 = &self->_lf_default__set_speed_0;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_0._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_set_speed_1 = &self->_lf_default__set_speed_1;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_1._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _bldcreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _bldcreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _bldcreaction_function_2;
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
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__set_speed_0.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set_speed_0.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_speed_0_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set_speed_0.reactions = &self->_lf__set_speed_0_reactions[0];
    self->_lf__set_speed_0.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set_speed_0.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set_speed_0.tmplt.type.element_size = sizeof(float);
    self->_lf__set_speed_1.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set_speed_1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_speed_1_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set_speed_1.reactions = &self->_lf__set_speed_1_reactions[0];
    self->_lf__set_speed_1.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set_speed_1.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set_speed_1.tmplt.type.element_size = sizeof(float);
    return self;
}
