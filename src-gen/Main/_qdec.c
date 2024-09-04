#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/Encoder/QDEC.h"
#include "_qdec.h"
// *********** From the preamble, verbatim:
#line 23 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Encoder.lf"
UART_HandleTypeDef huart3;
ADC_HandleTypeDef hadc1;
static int printVals = true;
static int printcnt = 0;
static int printcnt_lim = 50;

uint8_t qdec_reset[1]= {"A"};

uint8_t req_qdec[6]=  {'l', 'm', 'f', 'g', 'h', 'i'};
uint8_t req_sea[6]=   {'d', 'e', '0', '0', '0', '0'};

float cpr_qdec[6]=   {52000, 52000, 4000, 40000, 40000, 40000};
float cpr_sea[6]=     {40000, 40000, 40000, 40000, 40000, 40000};
float pi = 3.14159;

uint8_t data0[8];
uint8_t data1[8];
uint8_t data2[8];
uint8_t data3[8];
uint8_t data4[8];
uint8_t data5[8];
uint8_t data6[8];

static void MX_UART3_Init(void) {
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 921600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
}

static void MX_ADC1_Init(void) {
  ADC_ChannelConfTypeDef sConfig = {0};

  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK) {
    Error_Handler();
  }

  sConfig.Channel = ADC_CHANNEL_14;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    Error_Handler();
  }
}

static long get_ticks(char msg, uint8_t* data) {
  HAL_UART_Transmit(&huart3, &(msg), 1, HAL_MAX_DELAY);
  HAL_UART_Receive(&huart3, data, 7, HAL_MAX_DELAY);

  // HAL_UART_Transmit_IT(&huart3, &(msg), 1);
  // HAL_UART_Receive_IT(&huart3, data, 7);
  long count = data[0] + (data[1]<<8) + (data[2]<<16) + (data[3]<<24) + (data[4]<<32) + (data[5]<<40) + (data[6]<<48) + (data[7]<<56);

  if (printVals && printcnt>printcnt_lim) {
    printf("[%c]:%ld  ", msg, count);
  }
  return count;

}
const int LEN = 20;
static int hist[20] ={0, 0, 0, 0, 0, 0, 0};
static int med_ind = 0;

static int get_avg_r(uint16_t value) {
  hist[med_ind] = (int)value;
  med_ind = (med_ind >= LEN)? 0 : med_ind+1;

  int sum = 0;
  for (int i=0; i<LEN; i++) {
    sum += hist[i];
  }
  return sum/LEN;
}
#line 101 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_qdec.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _qdecreaction_function_0(void* instance_args) {
    _qdec_self_t* self = (_qdec_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 119 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Encoder.lf"
    MX_UART3_Init();
    MX_ADC1_Init();
    
    HAL_UART_Transmit(&huart3, qdec_reset, 1, HAL_MAX_DELAY);
#line 115 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_qdec.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _qdecreaction_function_1(void* instance_args) {
    _qdec_self_t* self = (_qdec_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _qdec_reset_qdec_t* reset_qdec = self->_lf_reset_qdec;
    int reset_qdec_width = self->_lf_reset_qdec_width; SUPPRESS_UNUSED_WARNING(reset_qdec_width);
    #line 126 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Encoder.lf"
    HAL_UART_Transmit(&huart3, qdec_reset, 1, HAL_MAX_DELAY);
#line 125 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_qdec.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _qdecreaction_function_2(void* instance_args) {
    _qdec_self_t* self = (_qdec_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    int qdec_out_width = self->_lf_qdec_out_width; SUPPRESS_UNUSED_WARNING(qdec_out_width);
    _qdec_qdec_out_t** qdec_out = self->_lf_qdec_out_pointers;
    int sea_out_width = self->_lf_sea_out_width; SUPPRESS_UNUSED_WARNING(sea_out_width);
    _qdec_sea_out_t** sea_out = self->_lf_sea_out_pointers;
    #line 132 "/Users/naichenzhao/Desktop/BML/lf_usm/src/lib/Encoder.lf"
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    int dac_raw = get_avg_r(HAL_ADC_GetValue(&hadc1));
    if(dac_raw > 2048)
      dac_raw = dac_raw - 4096;
    float R_angle = (0.088 * (float) (dac_raw - 660));
    
    // Set all the positional QDEC values
    lf_set(qdec_out[0], 2*pi* ((float) (get_ticks(req_qdec[0], &data0)) /cpr_qdec[0])); // Get x position
    lf_set(qdec_out[1], 2*pi* ((float) (get_ticks(req_qdec[1], &data1)) /cpr_qdec[1])); // Get y position
    lf_set(qdec_out[2], 2*pi* ((float) (get_ticks(req_qdec[2], &data2)) /cpr_qdec[2])); // Get z position
    lf_set(qdec_out[3], R_angle);
    if (printVals && printcnt>printcnt_lim) {
        printf("[R]:%d  ", dac_raw);
      }                                                     // Get r position
    lf_set(qdec_out[4], -2*pi* ((float) (get_ticks(req_qdec[4], &data3)) /cpr_qdec[4])); // Get a1 position
    lf_set(qdec_out[5], 2*pi* ((float) (get_ticks(req_qdec[5], &data4)) /cpr_qdec[5])); // Get a2 position
    
    
    // Set all the SEA QDEC values
    lf_set(sea_out[0], 2*pi* ((float) (get_ticks(req_sea[0], &data5)) /cpr_sea[0])); // Get x sea position
    lf_set(sea_out[1], 2*pi* ((float) (get_ticks(req_sea[1], &data6)) /cpr_sea[1])); // Get y sea position
    lf_set(sea_out[2], 0);
    lf_set(sea_out[3], 0);
    lf_set(sea_out[4], 0);
    lf_set(sea_out[5], 0);
    
    long end = HAL_GetTick();
    
    // printf("start: %ld, end: %ld, diff: %ld\r\n", start, end, (end-start));
    
    if (printVals && printcnt>printcnt_lim) {
      printf("\r\n");
    }
    
    if (printcnt > printcnt_lim) {
      printcnt = 0;
    } else {
      printcnt ++;
    }
#line 176 "/Users/naichenzhao/Desktop/BML/lf_usm/src-gen/Main/_qdec.c"
}
#include "include/api/reaction_macros_undef.h"
_qdec_self_t* new__qdec() {
    _qdec_self_t* self = (_qdec_self_t*)lf_new_reactor(sizeof(_qdec_self_t));
    // Set input by default to an always absent default input.
    self->_lf_reset_qdec = &self->_lf_default__reset_qdec;
    // Set the default source reactor pointer
    self->_lf_default__reset_qdec._base.source_reactor = (self_base_t*)self;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _qdecreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _qdecreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _qdecreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__trigger.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_2;
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    self->_lf__trigger.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__trigger.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    self->_lf__reset_qdec.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__reset_qdec.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__reset_qdec_reactions[0] = &self->_lf__reaction_1;
    self->_lf__reset_qdec.reactions = &self->_lf__reset_qdec_reactions[0];
    self->_lf__reset_qdec.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__reset_qdec.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__reset_qdec.tmplt.type.element_size = sizeof(bool);
    return self;
}
