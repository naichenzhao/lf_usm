#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/USM/USM.h"
#include "_usm.h"
// *********** From the preamble, verbatim:
#line 20 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/USM.lf"
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

static void MX_TIM2_Init(void) {
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK) {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK) {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK) {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim2);
}

static void MX_TIM3_Init(void) {
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  // htim3.Init.Period = 65535;
  htim3.Init.Period = 1000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK) {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK) {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK) {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2) != HAL_OK) {
    Error_Handler();
  }
  HAL_TIM_MspPostInit(&htim3);
}

static void USM_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  // Name, Direction, Enable
  // USM_2, PA12, PA11
  // USM_3, PB0, PA4
  // USM_4, PB2, PB1

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
#line 126 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_usm.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _usmreaction_function_0(void* instance_args) {
    _usm_self_t* self = (_usm_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 141 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/USM.lf"
    MX_TIM2_Init();
    MX_TIM3_Init();
    USM_GPIO_Init();
    
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
    
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); // USM_2, PB10
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // USM_3, PB4
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // USM_4, PB5
#line 147 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_usm.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _usmreaction_function_1(void* instance_args) {
    _usm_self_t* self = (_usm_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _usm_set_speed_2_t* set_speed_2 = self->_lf_set_speed_2;
    int set_speed_2_width = self->_lf_set_speed_2_width; SUPPRESS_UNUSED_WARNING(set_speed_2_width);
    _usm_set_speed_3_t* set_speed_3 = self->_lf_set_speed_3;
    int set_speed_3_width = self->_lf_set_speed_3_width; SUPPRESS_UNUSED_WARNING(set_speed_3_width);
    _usm_set_speed_4_t* set_speed_4 = self->_lf_set_speed_4;
    int set_speed_4_width = self->_lf_set_speed_4_width; SUPPRESS_UNUSED_WARNING(set_speed_4_width);
    #line 155 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Motor_Drivers/USM.lf"
    // Set USM enable values
    
    
    // For some reason, setting the motor direction doesnt work unless we add a small delay in between
    //      Im not sure why but we need to figure out why this is happning
    //      TODO: Figure out why this is fucked up
    //      TODO; See if we can decrease the amount we delay by
    // HAL_Delay(1);
    // Update: It seems like moving the direction set above the enable pins resolves this issue
    //      Though I am still not sure why this is happening
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, set_speed_3->value >= 0);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, set_speed_4->value >= 0);
    
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4,  (set_speed_3->value > 0.01 || set_speed_3->value < -0.01) && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)); // && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1,  (set_speed_4->value > 0.01 || set_speed_4->value < -0.01) && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)); // && HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
    
    
    int p = 0;
    if(set_speed_3->value < 0) {
      p = (int)((1000 * -set_speed_3->value * 0.8)/100);
    } else {
      p = (int)((1000 * set_speed_3->value * 0.8)/100);
    }
    p = (p > 500)? 500: p;
    TIM3->CCR1 = p;
    
    if(set_speed_4->value < 0) {
      p = (int)((1000 * -set_speed_4->value * 0.65)/100);
    } else {
      p = (int)((1000 * set_speed_4->value * 0.65)/100);
    }
    p = (p > 420)? 420: p;
    TIM3->CCR2 = p;
#line 194 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_usm.c"
}
#include "include/api/reaction_macros_undef.h"
_usm_self_t* new__usm() {
    _usm_self_t* self = (_usm_self_t*)lf_new_reactor(sizeof(_usm_self_t));
    // Set input by default to an always absent default input.
    self->_lf_set_speed_2 = &self->_lf_default__set_speed_2;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_2._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_set_speed_3 = &self->_lf_default__set_speed_3;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_3._base.source_reactor = (self_base_t*)self;
    // Set input by default to an always absent default input.
    self->_lf_set_speed_4 = &self->_lf_default__set_speed_4;
    // Set the default source reactor pointer
    self->_lf_default__set_speed_4._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _usmreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _usmreaction_function_1;
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
    self->_lf__set_speed_2.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set_speed_2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_speed_2_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set_speed_2.reactions = &self->_lf__set_speed_2_reactions[0];
    self->_lf__set_speed_2.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set_speed_2.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set_speed_2.tmplt.type.element_size = sizeof(float);
    self->_lf__set_speed_3.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set_speed_3.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_speed_3_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set_speed_3.reactions = &self->_lf__set_speed_3_reactions[0];
    self->_lf__set_speed_3.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set_speed_3.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set_speed_3.tmplt.type.element_size = sizeof(float);
    self->_lf__set_speed_4.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__set_speed_4.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__set_speed_4_reactions[0] = &self->_lf__reaction_1;
    self->_lf__set_speed_4.reactions = &self->_lf__set_speed_4_reactions[0];
    self->_lf__set_speed_4.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__set_speed_4.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__set_speed_4.tmplt.type.element_size = sizeof(float);
    return self;
}
