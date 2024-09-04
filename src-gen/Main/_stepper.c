#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/Stepper/Stepper.h"
#include "_stepper.h"
// *********** From the preamble, verbatim:
#line 19 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/Stepper.lf"
TIM_HandleTypeDef htim8;
TIM_HandleTypeDef htim14;

static int motor_en0 = 1;
static int motor_en1 = 1;

static int counter = 0;

static void MX_TIM8_Init(void) {
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 0;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 65535;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK) {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK) {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK) {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK) {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim8);
}

static void MX_TIM14_Init(void) {
  TIM_OC_InitTypeDef sConfigOC = {0};
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 0;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 65535;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim14, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim14);
}

static void Stepper_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOC_CLK_ENABLE();
  // Name, Pulse, Direction
  // Stepper 1, PC5       --> Mapped to timer 8
  // Stepper 2, PC13      --> Mapped to timer 14

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC5 PC13*/
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
#line 110 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_stepper.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _stepperreaction_function_0(void* instance_args) {
    _stepper_self_t* self = (_stepper_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 124 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/Stepper.lf"
    MX_TIM8_Init();
    MX_TIM14_Init();
    Stepper_GPIO_Init();
    
    HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim14, TIM_CHANNEL_1);
#line 126 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_stepper.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _stepperreaction_function_1(void* instance_args) {
    _stepper_self_t* self = (_stepper_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _stepper_set_speed_0_t* set_speed_0 = self->_lf_set_speed_0;
    int set_speed_0_width = self->_lf_set_speed_0_width; SUPPRESS_UNUSED_WARNING(set_speed_0_width);
    _stepper_set_speed_1_t* set_speed_1 = self->_lf_set_speed_1;
    int set_speed_1_width = self->_lf_set_speed_1_width; SUPPRESS_UNUSED_WARNING(set_speed_1_width);
    #line 133 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/Stepper.lf"
    // // Set Stepper Pulse and Dir variables
    int speed_1;
    int speed_2;
    if(set_speed_0->value < 0) { // Use TIM8
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
      speed_1 = (int)((5000 * (101 + set_speed_0->value))/100) + 1700;
    } else {
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
      speed_1 = (int)((5000 * (101 - set_speed_0->value))/100) + 1700;
    }
    TIM8->ARR = speed_1;
    TIM8->CCR1 = speed_1/2;
    
    if(set_speed_1->value < 0) { // Use TIM14
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
      speed_2 = (int)((5000 * (101 + set_speed_1->value))/100) + 1400;
    } else {
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
      speed_2 = (int)((5000 * (101 - set_speed_1->value))/100) + 1400;
    }
    TIM14->ARR = speed_2;
    TIM14->CCR1 = speed_2/2;
    
    
    // Set Stepper enable values
    if(set_speed_0->value < 1 && set_speed_0->value > -1) {
      TIM8->CCR1 = 0;
    }
    if (set_speed_1->value < 1 && set_speed_1->value > -1) {
      TIM14->CCR1 = 0;
    }
#line 168 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_stepper.c"
}
#include "include/api/reaction_macros_undef.h"
_stepper_self_t* new__stepper() {
    _stepper_self_t* self = (_stepper_self_t*)lf_new_reactor(sizeof(_stepper_self_t));
    // Set input by default to an always absent default input.
    self->_lf_set_speed_0 = &self->_lf_default__set_speed_0;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_0._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_set_speed_1 = &self->_lf_default__set_speed_1;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_1._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _stepperreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _stepperreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
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
