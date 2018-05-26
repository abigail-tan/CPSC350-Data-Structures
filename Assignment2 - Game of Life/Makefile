BUILD_FLAGS = -W -Wall -pedantic 
CC = g++
RM = rm
OUT = *.out

all: GameOfLife.out

LifeGrid.o: Makefile LifeGrid.cpp
	$(CC) $(BUILD_FLAGS) -c LifeGrid.cpp -o LifeGrid.o

UserInput.o: Makefile UserInput.cpp
	$(CC) $(BUILD_FLAGS) -c UserInput.cpp -o UserInput.o

GameOfLife.out: Makefile UserInput.o LifeGrid.o main.cpp
	$(CC) $(BUILD_FLAGS) UserInput.o LifeGrid.o main.cpp -o GameOfLife.out

clean:
	$(RM) $(OUT)