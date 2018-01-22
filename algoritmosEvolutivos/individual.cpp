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
#include <random>

using namespace std;

Individual::Individual(){ 
  nGenes=0;
  genes=0;
}

//************************************************//

Individual::Individual(int numGenes){
  nGenes=numGenes;
  genes=(int*) malloc(nGenes * sizeof(int));
}

//************************************************//

Individual::~Individual(){
  if(genes!=0)
    free(genes);
}

//************************************************//

void Individual::init(){
  if(genes==0)
    genes=(int*) malloc(nGenes * sizeof(int));

  random_device rd;
  mt19937 generator{rd()};

  for(int i=0;i<nGenes;i++){
    genes[i]=i;
  }

  for(int i=0;i<nGenes;i++){
    uniform_int_distribution<> dis{i, nGenes-1};
    swapGenes(i,dis(generator));
  }

}

//************************************************//

void Individual::calculateFitness(Matrix* flowMatrix,Matrix* distanceMatrix,GAType type){
  fitness=0;
  for (int i=0;i<nGenes;i++) {
      for (int j=0;j<nGenes;j++) {
          fitness+=flowMatrix->get(i,j) * distanceMatrix->get(genes[i],genes[j]);
      }
  }
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

int Individual::getFitness(){
  return fitness;
}


//************************************************//

void Individual::setNGenes(int size){
  nGenes=size;
}

//************************************************/

void Individual::crossover(int cutOff1,int cutOff2,int* genesP1, int* genesP2){

  bool* mapValue=(bool*) malloc(nGenes * sizeof(bool));
  for(int i=0;i<nGenes;i++)
    mapValue[i]=false;

  for(int i=cutOff1;i<cutOff2;i++){
      genes[i]=genesP1[i];
      mapValue[genes[i]]=true;
  }

  int currentValue=cutOff2;

  for(int i=cutOff2;i<nGenes;i++){

    while(mapValue[genesP2[currentValue]]){
      currentValue++;
      if(currentValue==nGenes)
        currentValue=0;
    }
    genes[i]=genesP2[currentValue];
    mapValue[genes[i]]=true;

  }

  for(int i=0;i<cutOff1;i++){
    while(mapValue[genesP2[currentValue]]){
      currentValue++;
      if(currentValue==nGenes)
        currentValue=0;
    }
    genes[i]=genesP2[currentValue];
    mapValue[genes[i]]=true;
  }

  free(mapValue);

}


//************************************************/
string Individual::toString(){
  string result="[";

  for(int i=0;i<nGenes;i++)
    result+=to_string(genes[i])+",";

  result+="]";
  return result;
}

//************************************************/

void Individual::localSearch(){


}
