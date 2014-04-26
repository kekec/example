<!--
readme.markdown
Paul Wiegele 2014
wiegele.paul@gmail.com
--> 

#content

  * latch.cpp        implementation of latch
  * latch.h          header of latch
  * makefile         builds, run, checks and debugs 
  * motor.cpp        implementation of motor
  * motor.h          header of motor
  * readme.markdown  holds the documentation
  * sensor.cpp       implementation of sensor
  * sensor.h         header of sensor
  * test.cpp         instantiates all objects and implements FSM

#implementation
  The latch class consists of the motor and the sensor. Opon calling
  the constructor of latch both classes are initialized.
  The test file creates all objects and implements a FSM. It loops
  over the contents of the sensor array and sums up all values. The
  implementation assumes that summing up all values does cause any overflow (ST_SUM). 
  In ST_CAL the average value of the sensor array is calculated. ST_SEEK_POS 
  tries to find the calculates average value within the sensor array. 
  If it is not found we enter ST_SEEK_MIN_DIST which loops over all values 
  in the sensor array and tries to find the sensor value heaving the 
  smallest distance to the avg value. Finally ST_SET_MOTOR sets the motor 
  to the sensor value of the minimal distance and opens the door.
  
#built
  Use "make" to build src files

#run
  Use "make run" to execute binary

#issues
  latch.cpp:[23-24]
  In order to store the values of the sensor array I used a buffer that 
  is allocated as an auto variable. A pointer to this buffer is passed 
  to the latch class and to the sensor class. I am not sure why the assigment
  of the pointers did not work.  When debugging with gdb I was not able to see the assignment of the pointers.
  I used memcpy to copy the content of the pointers.
