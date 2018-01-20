// *********************************************************************
// **
// ** Copyright (C) 2017-2018 Antonio David López Machado
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************

#include <stdlib.h>
#include "population.h"
#include "individual.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Population::Population(){
  size=0;
  population=0;
}

//************************************************//

Population::Population(int sizeP){
  init(sizeP);
}

//************************************************//

Population::~Population(){
  if(size>0)
    delete[] population;
}

//************************************************//

void Population::init(int sizeP){
  size=sizeP;
  if(size>0){
    population=new Individual[size];

    for(int i=0;i<size; i++){
      population[i].setNGenes(size);
      population[i].init();
    }
  }
}

//************************************************//

void Population::calculateFitness(){
  fitness=0;
    for(int i=0;i<size; i++)
      fitness+=population[i].getFitness();

}

//************************************************//

int Population::getFitness(){
  return fitness;
}

//************************************************//

Individual* Population::getPopulation(){
  return population;
}

//************************************************//

string Population::toString(){
  string result="";

  for(int i=0;i<size;i++)
    result+=population[i].toString()+"\n";

  return result;
}
