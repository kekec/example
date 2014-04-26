#define SENSOR_DATA {100, 101, 105, 110, 210, 100, 102, 110, 150, 100}
#define MAX_SENSOR_DATA 10

class CSensor
{

  public:
  bool Calibrate(); // calibrates the sensor
  void ReadData(int *data); // Reads the data from the sensor

};
