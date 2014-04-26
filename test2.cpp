#include <iostream>
#include "motor.h"
#include "assert.h"
#include "sensor.h"
#include "latch.h"
#include <cmath>
#define ST_SUM 0
#define ST_CAL 1
#define ST_SEEK_MIN_DIST 2
#define ST_SEEK_POS 3
#define ST_SET_MOTOR 4

main()
{
  CMotor motor;
  CSensor sensor;

  int ptr[MAX_SENSOR_DATA];

  unsigned int state=ST_SUM;
  unsigned int cnt=0;
  unsigned int min_pos=0;
  int sum=0;
  float avg=0, new_min=0, old_min=10000000;

  CLatch latch(&motor, &sensor, ptr);

  while(1)
  {
    switch(state)
    {
      case ST_SUM:
        latch.moveMotor(cnt++);
        sum+=latch.getData();
        if(cnt == MAX_SENSOR_DATA)
          state=ST_CAL;
      break;

      case ST_CAL:
        avg=((float)sum)/((float)cnt);
        cnt=0;
        state=ST_SEEK_POS;
      break;

      case ST_SEEK_POS:
        if(cnt == MAX_SENSOR_DATA) //since avg value is not in array
        {
          state=ST_SEEK_MIN_DIST;
          cnt=0;
          break;
        }

        latch.moveMotor(cnt++);
        if(((float)latch.getData()) == avg)
        { 
          std::cout << "avg found " << cnt << std::endl;
          return 0;
        }
      break;

      case ST_SEEK_MIN_DIST:
        if(cnt == MAX_SENSOR_DATA) //since avg value is not in array
        {
          state=ST_SET_MOTOR;
          break;
        }

        latch.moveMotor(cnt++);
        new_min = std::abs(avg-((float)latch.getData()));
        if(new_min < old_min)
        {
          old_min = new_min;
          min_pos = cnt-1;
        }
      break;

      case ST_SET_MOTOR:
          latch.moveMotor(min_pos);
          return 0;
      break;
 
    }
  }

  return 0;
}