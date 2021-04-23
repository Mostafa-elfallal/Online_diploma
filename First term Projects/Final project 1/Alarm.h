#ifndef __ALARM__
#define __ALARM__
#include "driver.h"
// A wise man once said : "Don't ever use hard coded numbers." ;;;
#define ON_KEY 0
#define OFF_KEY 1
#define DUR 3000000 	//fake 60 secs  actually they are 5 secs on proteus
#define ACTUATOR_PIN 13

void Delay(int nCount);
void Ctrl_Alarm_actuator(int i);

#endif