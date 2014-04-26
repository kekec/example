#include <iostream>
#include "motor.h"
#include "assert.h"
#include "sensor.h"
#include "latch.h"

main()
{
  CMotor motor;
  CSensor sensor;

  int ptr[MAX_SENSOR_DATA];
  std::cout << "this is main calling motor" << std::endl;
  motor.ResetMotor();
  motor.MoveMotor(3);

  if(!sensor.Calibrate())
    return -1;

  std::cout << "sensor ready to use" << std::endl;
  sensor.ReadData(ptr);
  int i = 0;
  while( i < MAX_SENSOR_DATA )
  {
    std::cout << "ptr[" << i << "] = " << ptr[i]  << std::endl;
    i++;
  }

  CLatch latch(&motor, &sensor, ptr);

  std::cout << "latchstate is " << latch.getLatchState() << std::endl;

  int j=0;
  while( j < MAX_SENSOR_DATA )
  {
    latch.moveMotor(j);
    std::cout << "latch[" << j << "] = " << latch.getData()  << std::endl;
    j++;
  }

  std::cout << "latchstate is " << latch.getLatchState() << std::endl;
  return 0;
}
