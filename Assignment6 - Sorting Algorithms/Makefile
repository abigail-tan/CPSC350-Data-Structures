BUILD_FLAGS = -W -Wall -pedantic 
CC = g++
RM = rm
OUT = *.out

all: a.out

Simulation.o: Makefile Simulation.cpp
	$(CC) $(BUILD_FLAGS) -c Simulation.cpp -o Simulation.o

a.out: Makefile Simulation.o main.cpp
	$(CC) $(BUILD_FLAGS) Simulation.o main.cpp -o a.out

clean:
	$(RM) $(OUT)