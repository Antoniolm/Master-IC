#Compiler
CC = g++

#Compiler flags
CFLAGS  = -g -Wall

#Target
TARGET = main
DEPENDENCIES = reader.cpp matrix.cpp individual.cpp population.cpp  geneticAlgorithm/*

all: $(TARGET)

$(TARGET): $(TARGET).cpp reader.cpp matrix.cpp individual.cpp population.cpp geneticAlgorithm/gaStandar.cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(DEPENDENCIES) -std=c++0x

clean:
	$(RM) $(TARGET)
# la poblacion[size = sizeProblem]  V
# hacer permutaciones aleatorias para inicializarlas
# cojo el primero y lo cambio con el n-1
# la funcion que evalua una permutación ( calcula el fitness ) es la que usa las matriz de distancia y flujo
