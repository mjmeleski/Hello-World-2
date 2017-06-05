/* nano-cc-el.ino
 *  
 *  Nano V3 based Constant Current Electronic Load
 *  10V full scale voltage measurement
 *  
 */


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/////////////////////////////////////////////////
#define SWR_VERSION "ver 0.4.25"
#define WELCOME_MSG "ENP252 CC E-LOAD"


/////////////////////////////////////////////////
//// SYSTEM CONSTANTS
//
// POWER SUPPLY
#define DAC_NOMINAL_VCC_MV  4780  // when powered from USB, 4830, else 5000
//
// PWM DAC
#define DAC_RSENSE_CONDUCTANCE 10 // 0.1 Ohm sense resistor
#define DAC_NOMINAL_LSB_MV  (DAC_NOMINAL_VCC_MV / 1101 / 255)
#define DAC_NOMINAL_MSB_MV  (DAC_NOMINAL_VCC_MV / 11 / 255 )
#define DAC_NOMINAL_MSB_MA  (DAC_NOMINAL_MSB_MV * DAC_RSENSE_CONDUCTANCE)
#define DAC_NOMINAL_LSB_MA  (DAC_NOMINAL_LSB_MV * DAC_RSENSE_CONDUCTANCE)
//
// ADC acquisition
#define ADC_VREF_MV 2492
#define ADC_VDUT_ATTENUATION    4 //[V/V]
#define ADC_IDUT_GAIN           1 //[A/V]
#define ADC_VIREF_ATTENUATION   1 //[V/V]
#define ADC_WINDOW_AVG_WEIGHT   16
#define ADC_NOMINAL_LSB_MV      (ADC_VREF_MV/1023)
#define ADC_NOMINAL_LSB_MA      (ADC_NOMINAL_LSB_MV/ADC_IDUT_GAIN)
//
// ASCII User Interface constants
#define UI_DELIMITERS " ,="
#define UI_INPUT_BUFFER_SIZE 30
#define UI_MAX_TOKENS   (2*10)
//