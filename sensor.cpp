#include "sensor.h"
#include <iostream>
#include <string.h>

bool CSensor::Calibrate()
{
  //note sure what todo here
  return 1;
}

void CSensor::ReadData(int * data)
{

  int helper[] =  SENSOR_DATA;
  memcpy(data, helper, MAX_SENSOR_DATA*sizeof(int));
}

