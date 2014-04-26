// motor.cpp
// Paul Wiegele 2014
// wiegele.paul@gmail.com

#include "motor.h"
#include <iostream>

CMotor::CMotor()
{
  mPos=0;
}

void CMotor::ResetMotor()
{
  mPos=0;
  std::cout << "Reset" << std::endl;
}

void CMotor::MoveMotor(unsigned int distance)
{
  mPos = distance;
  std::cout << "MoveMotor to " << distance << std::endl;
}

unsigned int CMotor::getCurrentPos()
{
  return mPos;
}

void CMotor::printCurrentPos()
{
  std::cout << "Current motor pos: " << mPos << std::endl;
}
