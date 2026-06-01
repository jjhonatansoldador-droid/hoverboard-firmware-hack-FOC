// Define to prevent recursive inclusion
#ifndef CONFIG_H
#define CONFIG_H

#include "stm32f1xx_hal.h"

// ############################### VARIANT SELECTION ###############################
#if !defined(PLATFORMIO)
  //#define VARIANT_ADC // Variant for control via ADC input
  #define VARIANT_USART // Variant for Serial USART control
  //#define VARIANT_NUNCHUK // Variant for Nunchuk controlled vehicle build
  //#define VARIANT_PPM // Variant for RC-Remote with PPM-Sum Signal
  //#define VARIANT_PWM // Variant for RC-Remote with PWM Signal
  //#define VARIANT_IBUS // Variant for RC-Remotes with FLYSKY IBUS
  //#define VARIANT_HOVERCAR // Variant for HOVERCAR build
  //#define VARIANT_HOVERBOARD // Variant for HOVERBOARD build
  //#define VARIANT_TRANSPOTTER // Variant for TRANSPOTTER build
  //#define VARIANT_SKATEBOARD // Variant for SKATEBOARD build
#endif
// ########################### END OF VARIANT SELECTION ############################


// ############################### DO-NOT-TOUCH SETTINGS ###############################
#define PWM_FREQ 16000
#define DEAD_TIME 48
#ifdef VARIANT_TRANSPOTTER
  #define DELAY_IN_MAIN_LOOP 2
#else
  #define DELAY_IN_MAIN_LOOP 5
#endif
#define TIMEOUT 20
#define A2BIT_CONV 50

#define ADC_CONV_TIME_1C5 (14)
#define ADC_CONV_TIME_7C5 (20)
#define ADC_CONV_TIME_13C5 (26)
#define ADC_CONV_TIME_28C5 (41)
#define ADC_CONV_TIME_41C5 (54)
#define ADC_CONV_TIME_55C5 (68)
#define ADC_CONV_TIME_71C5 (84)
#define ADC_CONV_TIME_239C5 (252)

#define ADC_CONV_CLOCK_CYCLES (ADC_CONV_TIME_7C5)
#define ADC_CLOCK_DIV (4)
#define ADC_TOTAL_CONV_TIME (ADC_CLOCK_DIV * ADC_CONV_CLOCK_CYCLES)
// ########################### END OF DO-NOT-TOUCH SETTINGS ############################

// ############################### BOARD VARIANT ###############################
#define BOARD_VARIANT 0
// ######################## END OF BOARD VARIANT ###############################

// ############################### BATTERY ###############################
#define BAT_FILT_COEF 655
#define BAT_CALIB_REAL_VOLTAGE 3970
#define BAT_CALIB_ADC 1492
#define BAT_CELLS 10
#define BAT_LVL2_ENABLE 0
#define BAT_LVL1_ENABLE 1
#define BAT_DEAD_ENABLE 1
#define BAT_BLINK_INTERVAL 80
#define BAT_LVL5 (390 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
#define BAT_LVL4 (380 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
#define BAT_LVL3 (370 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
#define BAT_LVL2 (360 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
#define BAT_LVL1 (350 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
#define BAT_DEAD (337 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE
// ######################## END OF BATTERY ###############################

// ############################### TEMPERATURE ###############################
#define TEMP_FILT_COEF 655
#define TEMP_CAL_LOW_ADC 1655
#define TEMP_CAL_LOW_DEG_C 358
#define TEMP_CAL_HIGH_ADC 1588
#define TEMP_CAL_HIGH_DEG_C 489
#define TEMP_WARNING_ENABLE 0
#define TEMP_WARNING 600
#define TEMP_POWEROFF_ENABLE 0
#define TEMP_POWEROFF 650
// ######################## END OF TEMPERATURE ###############################

// ############################### MOTOR CONTROL #########################
#define COM_CTRL 0
#define SIN_CTRL 1
#define FOC_CTRL 2

#define OPEN_MODE 0
#define VLT_MODE 1
#define SPD_MODE 2
#define TRQ_MODE 3

#define MOTOR_LEFT_ENA
#define MOTOR_RIGHT_ENA

#define CTRL_TYP_SEL FOC_CTRL
#define CTRL_MOD_REQ TRQ_MODE // ← TORQUE mode (alterado)
#define DIAG_ENA 1

#define I_MOT_MAX 8 // ← alterado de 15 para 20
#define I_DC_MAX 10 // ← alterado de 17 para 22
#define N_MOT_MAX 800 // ← alterado de 1000 para 800

#define FIELD_WEAK_ENA 0
#define FIELD_WEAK_MAX 5
#define PHASE_ADV_MAX 25
#define FIELD_WEAK_HI 1000
#define FIELD_WEAK_LO 750

//#define STANDSTILL_HOLD_ENABLE // ← ativado
//define ELECTRIC_BRAKE_ENABLE // ← ativado
#define ELECTRIC_BRAKE_MAX 100
#define ELECTRIC_BRAKE_THRES 120
// ########################### END OF MOTOR CONTROL ########################

// ############################## DEFAULT SETTINGS ############################
#define INACTIVITY_TIMEOUT 8
#define BEEPS_BACKWARD 0 // ← alterado de 1 para 0
#define ADC_MARGIN 100
#define ADC_PROTECT_TIMEOUT 100
#define ADC_PROTECT_THRESH 200
#define AUTO_CALIBRATION_ENA

#define DEFAULT_RATE 320 // ← alterado de 480 para 320
#define DEFAULT_FILTER 3276 // ← alterado de 6553 para 3276
#define DEFAULT_SPEED_COEFFICIENT 16384
#define DEFAULT_STEER_COEFFICIENT 8192
// ######################### END OF DEFAULT SETTINGS ##########################

// ############################ VARIANT_USART SETTINGS ############################
#ifdef VARIANT_USART
  // #define SIDEBOARD_SERIAL_USART2 0
  // #define CONTROL_SERIAL_USART2 0
  // #define FEEDBACK_SERIAL_USART2

  #define CONTROL_SERIAL_USART3 0 // ← USART3 ativado (conector direito)
  #define FEEDBACK_SERIAL_USART3 // ← USART3 ativado

  #define PRI_INPUT1 3, -1000, 0, 1000, 0
  #define PRI_INPUT2 3, -1000, 0, 1000, 0
  #define FLASH_WRITE_KEY 0x1002
#endif
// ######################## END OF VARIANT_USART SETTINGS #########################

// ########################### UART SETTINGS ############################
#if defined(FEEDBACK_SERIAL_USART2) || defined(CONTROL_SERIAL_USART2) || defined(DEBUG_SERIAL_USART2) || defined(SIDEBOARD_SERIAL_USART2) || \
    defined(FEEDBACK_SERIAL_USART3) || defined(CONTROL_SERIAL_USART3) || defined(DEBUG_SERIAL_USART3) || defined(SIDEBOARD_SERIAL_USART3)
  #define SERIAL_START_FRAME 0xABCD
  #define SERIAL_BUFFER_SIZE 64
  #define SERIAL_TIMEOUT 160
#endif
#if defined(FEEDBACK_SERIAL_USART2) || defined(CONTROL_SERIAL_USART2) || defined(DEBUG_SERIAL_USART2) || defined(SIDEBOARD_SERIAL_USART2)
  #ifndef USART2_BAUD
    #define USART2_BAUD 115200
  #endif
  #define USART2_WORDLENGTH UART_WORDLENGTH_8B
#endif
#if defined(FEEDBACK_SERIAL_USART3) || defined(CONTROL_SERIAL_USART3) || defined(DEBUG_SERIAL_USART3) || defined(SIDEBOARD_SERIAL_USART3)
  #ifndef USART3_BAUD
    #define USART3_BAUD 115200
  #endif
  #define USART3_WORDLENGTH UART_WORDLENGTH_8B
#endif
// ########################### END OF UART SETTINGS ############################

// ############################### APPLY DEFAULT SETTINGS ###############################
#ifndef RATE
  #define RATE DEFAULT_RATE
#endif
#ifndef FILTER
  #define FILTER DEFAULT_FILTER
#endif
#ifndef SPEED_COEFFICIENT
  #define SPEED_COEFFICIENT DEFAULT_SPEED_COEFFICIENT
#endif
#ifndef STEER_COEFFICIENT
  #define STEER_COEFFICIENT DEFAULT_STEER_COEFFICIENT
#endif
#if defined(PRI_INPUT1) && defined(PRI_INPUT2) && defined(AUX_INPUT1) && defined(AUX_INPUT2)
  #define INPUTS_NR 2
#else
  #define INPUTS_NR 1
#endif
// ########################### END OF APPLY DEFAULT SETTING ############################

// ############################### VALIDATE SETTINGS ###############################
#if !defined(VARIANT_ADC) && !defined(VARIANT_USART) && !defined(VARIANT_NUNCHUK) && !defined(VARIANT_PPM) && !defined(VARIANT_PWM) && \
    !defined(VARIANT_IBUS) && !defined(VARIANT_HOVERCAR) && !defined(VARIANT_HOVERBOARD) && !defined(VARIANT_TRANSPOTTER) && !defined(VARIANT_SKATEBOARD)
  #error Variant not defined! Please check platformio.ini or Inc/config.h for available variants.
#endif

#if defined(CONTROL_SERIAL_USART2) && defined(SIDEBOARD_SERIAL_USART2)
  #error CONTROL_SERIAL_USART2 and SIDEBOARD_SERIAL_USART2 not allowed, choose one.
#endif
#if defined(CONTROL_SERIAL_USART3) && defined(SIDEBOARD_SERIAL_USART3)
  #error CONTROL_SERIAL_USART3 and SIDEBOARD_SERIAL_USART3 not allowed, choose one.
#endif
#if defined(DEBUG_SERIAL_USART2) && defined(FEEDBACK_SERIAL_USART2)
  #error DEBUG_SERIAL_USART2 and FEEDBACK_SERIAL_USART2 not allowed, choose one.
#endif
#if defined(DEBUG_SERIAL_USART3) && defined(FEEDBACK_SERIAL_USART3)
  #error DEBUG_SERIAL_USART3 and FEEDBACK_SERIAL_USART3 not allowed, choose one.
#endif
// ############################# END OF VALIDATE SETTINGS ############################
#define MULTIPLE_TAP_NR 4
#define MULTIPLE_TAP_HI 600
#define MULTIPLE_TAP_LO 200
#define MULTIPLE_TAP_TIMEOUT 2000
#endif
