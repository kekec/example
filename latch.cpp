// latch.cpp
// Paul Wiegele 2014
// wiegele.paul@gmail.com

#include "latch.h"
#include "assert.h"
#include "sensor.h"
#include "motor.h"
#include "string.h"

CLatch::CLatch(CMotor * motor, CSensor * sensor, int * buffer)
{
  assert(motor);
  assert(sensor);
  assert(buffer);
  mMotor = motor;
  mMotor->ResetMotor();

  mSensor = sensor;
  if(!mSensor->Calibrate())
    //OUch!

  mData=buffer;
  memcpy(&mData, &buffer, sizeof(int*));
  mSensor->ReadData(mData);

  mLatchState = DS_OPEN;
}

bool CLatch::getLatchState()
{
  return mLatchState;
}

void CLatch::setLatchState(bool newState)
{
  mLatchState = newState;
}

void CLatch::moveMotor(unsigned int distance)
{
  assert(distance >= 0 && distance < MAX_SENSOR_DATA);
  mMotor->MoveMotor(distance);
}

int CLatch::getData()
{
  return mData[mMotor->getCurrentPos()];
}

