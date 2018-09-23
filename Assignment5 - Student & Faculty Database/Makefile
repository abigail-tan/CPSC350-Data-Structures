BUILD_FLAGS = -W -Wall -pedantic 
CC = g++ -std=c++11
RM = rm
OUT = *.out *.o

all: a.out

Student.o: Makefile Student.cpp
	$(CC) $(BUILD_FLAGS) -c Student.cpp -o Student.o

Faculty.o: Makefile Faculty.cpp
	$(CC) $(BUILD_FLAGS) -c Faculty.cpp -o Faculty.o

checkFile.o: Makefile checkFile.cpp
	$(CC) $(BUILD_FLAGS) -c checkFile.cpp -o checkFile.o

Simulation.o: Makefile Simulation.cpp
	$(CC) $(BUILD_FLAGS) -c Simulation.cpp -o Simulation.o

a.out: Makefile Student.o Faculty.o checkFile.o Simulation.o main.cpp
	$(CC) $(BUILD_FLAGS) Student.o Faculty.o checkFile.o Simulation.o main.cpp -o a.out

clean:
	$(RM) $(OUT)