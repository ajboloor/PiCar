// INPUT - DESIRED RPM
// OUTPUT - PWM

#include <stdint.h>
#include "fp.h"
#include "signalproc.h"
#include "ddefs.h"

uint16_t PID = 1; // temporary constant
uint16_t PWM_curr;
uint16_t RPM_curr;
uint16_t PWM_err;
uint16_t RPM_err;

uint16_t toPWM(uint16_t RPM_des)
{
  if ( getData( BLDC_DUTY_CYCLE, &PWM_curr ) == DSHARE_OK );
  if ( getData( BLDC_HALL_SPEED, &RPM_curr ) == DSHARE_OK );
  
  RPM_err = RPM_des - RPM_curr;
  PWM_err = PID*RPM_err;
  PWM_curr += PWM_err;
  return PWM_curr;
}
