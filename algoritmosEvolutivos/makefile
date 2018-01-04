#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = main
DEPENDENCIES = reader.cpp matrix.cpp

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(DEPENDENCIES) -std=c++0x

clean:
	$(RM) $(TARGET)
