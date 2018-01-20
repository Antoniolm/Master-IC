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
#include "gaStandar.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

GAStandar::GAStandar(){
  population=0;
}

//************************************************//

GAStandar::GAStandar(int popuSize){
  populationSize=popuSize;
  population=0;
}
//************************************************//


GAStandar::~GAStandar(){
  if(population!=0){
    delete population;
    free(currentSelection);
  }
}

//************************************************//

void GAStandar::execute(Reader * reader){

  population=new Population(populationSize);
  currentSelection=(int*) malloc(populationSize * sizeof(int));

  population->calculateFitness(reader->getFlowMatrix(),reader->getDistanceMatrix());

  for(int i=0;i<3;i++){
      //optimizacion local -> no estandar solo los otros dos

      selection();

      crossover();

      mutation(); // mutation for each individual

      population->calculateFitness(reader->getFlowMatrix(),reader->getDistanceMatrix());
      cout<< "================================"<<endl;
      cout<< "Generation="<< i<<endl;

      cout<< "Fitness="<< population->getFitness()<<endl;

  }

}

//************************************************//

void GAStandar::mutation(){
  Individual* individual = population->getPopulation();
  int secondIndex;

  random_device rd;
  mt19937 generator{rd()};
  uniform_int_distribution<> probMutation{0, 99};
  uniform_int_distribution<> probGene{0, populationSize-1};

  for(int j=0;j<populationSize;j++){
      for(int i=0;i<populationSize;i++){
        if (probMutation(generator)< 5) {

          do{
            secondIndex=probGene(generator);
          }while(secondIndex==i);

          individual[j].swapGenes(i,secondIndex);

        }
      }
  }
}

//************************************************//

void GAStandar::crossover(){
  Population* newGeneration=new Population(populationSize);

  for(int i=0;i<populationSize/2;i++){
    int* genes1=population->getPopulation()[i].getGenes();
    int* genes2=population->getPopulation()[i+1].getGenes();

    newGeneration->getPopulation()[i].crossover(populationSize/2,genes1,genes2);
    newGeneration->getPopulation()[i+1].crossover(populationSize/2,genes2,genes1);

  }

  /*if(populationSize%2==1){
      newGeneration->getPopulation()[populationSize-1]=population->getPopulation()[populationSize-1];
  }*/

  delete population;
  population=newGeneration;
}

//************************************************//

void GAStandar::selection(){

    for(int i=0;i<populationSize;i++)
      currentSelection[i]=roulleteSelection();
}

//************************************************//

int GAStandar::roulleteSelection(){
  float sumFitness=0;
  float currentFitness=0;

  for(int i=0;i<populationSize;i++)
    sumFitness+=population->getPopulation()[i].getFitness();

  mt19937 generator(random_device{}() );
  uniform_real_distribution<> dist(0, sumFitness);
  float randNumber=dist(generator);

  for(int i=0;i<populationSize;i++){
    if(randNumber>=currentFitness && randNumber<=currentFitness+population->getPopulation()[i].getFitness())
      return i;

    currentFitness+=population->getPopulation()[i].getFitness();
  }

  return -1;
}
