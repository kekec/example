class CMotor;
class CSensor;

class CLatch
{
  public:
  CLatch(CMotor *motor, CSensor *sensor, int * buffer);
  bool getLatchState();
  void setLatchState(bool state);
  void moveMotor(unsigned int distance);
  int getData();

  private:
  bool mLatchState;
  CMotor *mMotor;
  CSensor *mSensor;
  int *mData;
};
