BUILD_FLAGS = -W -Wall -pedantic 
CC = g++
RM = rm
OUT = *.out
O = *.o 

all: a.out

DelimiterCheck.o: Makefile DelimiterCheck.cpp
	$(CC) $(BUILD_FLAGS) -c DelimiterCheck.cpp -o DelimiterCheck.o

a.out: Makefile DelimiterCheck.o main.cpp
	$(CC) $(BUILD_FLAGS) DelimiterCheck.o main.cpp -o a.out

clean:
	$(RM) $(OUT) $(O)