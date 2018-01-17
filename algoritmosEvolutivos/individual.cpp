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
#include "individual.h"
#include <string>
#include <iostream>

using namespace std;

Individual::Individual(){
  nGenes=0;
  genes=0;
  chromosome="";
}

//************************************************//

Individual::Individual(int numGenes){
  nGenes=numGenes;
  genes=(int*) malloc(nGenes * sizeof(int));
  chromosome="";
}
//************************************************//


Individual::~Individual(){
  free(genes);
}

//************************************************//

void Individual::init(){

}

//************************************************//

void Individual::calculateFitness(){
  fitness=0;
  for(int i=0;i<nGenes;i++)
    fitness+=genes[i];
}

//************************************************//

void Individual::swapGenes(int firstIndex, int secondIndex){
  int auxValue=genes[firstIndex];
  genes[firstIndex]=genes[secondIndex];
  genes[secondIndex]=auxValue;
}

//************************************************//

int * Individual::getGenes(){
  return genes;
}

//************************************************//

string Individual::getChromosome(){
  return chromosome;
}

//************************************************//

int Individual::getFitness(){
  return fitness;
}
