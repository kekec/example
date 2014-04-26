CC=g++
CFLAGS= -g

test2.o: test2.cpp
	$(CC) $(CFLAGS) -c test2.cpp
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
motor.o: motor.cpp
	$(CC) $(CFLAGS) -c motor.cpp	
sensor.o: sensor.cpp
	$(CC) $(CFLAGS) -c sensor.cpp
latch.o: latch.cpp
	$(CC) $(CFLAGS) -c latch.cpp


fin: test.o motor.o sensor.o latch.o
	$(CC) $(CFLAGS) -o fin motor.o sensor.o latch.o test.o

fin2: test2.o motor.o sensor.o latch.o
	$(CC) $(CFLAGS) -o fin2 motor.o sensor.o latch.o test2.o

clean:
	rm -f fin fin2 *.o
