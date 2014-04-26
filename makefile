CC=g++
CFLAGS= -g

test: test.o motor.o sensor.o latch.o
	$(CC) $(CFLAGS) -o test motor.o sensor.o latch.o test.o

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp
motor.o: motor.cpp
	$(CC) $(CFLAGS) -c motor.cpp	
sensor.o: sensor.cpp
	$(CC) $(CFLAGS) -c sensor.cpp
latch.o: latch.cpp
	$(CC) $(CFLAGS) -c latch.cpp

run: test
	./test
clean:
	rm -f test *.o
