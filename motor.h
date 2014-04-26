// motor.h
// Paul Wiegele 2014
// wiegele.paul@gmail.com

class CMotor
{

  public:
  CMotor();
  void ResetMotor(); // moves motor to the starting position
  void MoveMotor(unsigned int distance); // Moves motor to the measurement position
  unsigned int getCurrentPos();
  void printCurrentPos();
  
  private:
  unsigned int mPos;
};
