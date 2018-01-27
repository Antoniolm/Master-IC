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
#include <time.h>
#include "../individual.h"
#include "../population.h"

using namespace std;

GAStandar::GAStandar(){
  population=0;
  type=STANDAR;
}

//************************************************//

GAStandar::GAStandar(int popuSize,int sizeGene,GAType aType){
  populationSize=popuSize;
  geneSize=sizeGene;
  population=0;
  type=aType;
}
//************************************************//


GAStandar::~GAStandar(){
  if(population!=0){
    delete population;
    free(currentSelection);
  }
}

//************************************************//

void GAStandar::execute(int numGeneration,Reader * reader){
  clock_t start,startGeneration;
  start=clock();

  population=new Population(populationSize,geneSize);
  currentSelection=(int*) malloc(populationSize * sizeof(int));

  population->calculateFitness(reader->getFlowMatrix(),reader->getDistanceMatrix(),type);

  //cout<< population->toString();

  for(int i=0;i<numGeneration;i++){
      //optimizacion local -> no estandar solo los otros dos
      startGeneration=clock();

      selection();

      crossover();

      mutation(); // mutation for each individual

      population->calculateFitness(reader->getFlowMatrix(),reader->getDistanceMatrix(),type);
      cout<< "================================"<<endl;
      //cout<< population->toString();
      cout<< "Generation="<< i<<endl;

      population->printGenesSolution();
      cout<< "Fitness="<< population->getFitness()<<endl;
      cout<<"Time: "<< (float)(clock() - startGeneration)/CLOCKS_PER_SEC<<" seconds"<<endl;
  }
  cout<<"Total time: "<< (float)(clock() - start)/CLOCKS_PER_SEC<<" seconds"<<endl;

}

//************************************************//

void GAStandar::mutation(){
  Individual* individual = population->getPopulation();
  int secondIndex;
  float currentProb=5.0/(float)geneSize;

  random_device rd;
  mt19937 generator{rd()};
  uniform_real_distribution<> probMutation{0, 99};
  uniform_int_distribution<> probGene{0, geneSize-1};

  for(int j=0;j<populationSize;j++){
      for(int i=0;i<geneSize;i++){
        if (probMutation(generator)< currentProb) {

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
  Population* newGeneration=new Population(populationSize,geneSize);

  random_device rd;
  mt19937 generator{rd()};
  uniform_int_distribution<> probCutOff{0, geneSize-1};

  for(int i=0;i<populationSize/2;i++){

    int* genes1=population->getPopulation()[currentSelection[i]].getGenes();
    int* genes2=population->getPopulation()[currentSelection[i+1]].getGenes();

    int cutOff1,cutOff2;
    cutOff1=probCutOff(generator);

    do{
      cutOff2=probCutOff(generator);
    }while(cutOff1==cutOff2);

    if(cutOff2 < cutOff1){
      int aux= cutOff1;
      cutOff1=cutOff2;
      cutOff2=aux;
    }

    newGeneration->getPopulation()[i].crossover(cutOff1,cutOff2,genes1,genes2);
    newGeneration->getPopulation()[i+1].crossover(cutOff1,cutOff2,genes2,genes1);

  }

  delete population;
  population=newGeneration;
}

//************************************************//

void GAStandar::selection(){

    for(int i=0;i<populationSize;i++){
      currentSelection[i]=roulleteSelection();
    }
}

//************************************************//

int GAStandar::roulleteSelection(){
  float sumFitness=0;
  float fixedSumFitness=0;
  float currentFitness=0.0;

  float* fixedFitness=(float*) malloc(populationSize * sizeof(float));
  int minFitness=population->getPopulation()[0].getFitness();
  int maxFitness=population->getPopulation()[0].getFitness();

  //take min fitness, sumFitness and max fitness
  for(int i=0;i<populationSize;i++){
    sumFitness+=population->getPopulation()[i].getFitness();

    if(minFitness>population->getPopulation()[i].getFitness()){
      minFitness=population->getPopulation()[i].getFitness();
    }

    if(maxFitness<population->getPopulation()[i].getFitness()){
      maxFitness=population->getPopulation()[i].getFitness();
    }

  }

  //Invert value -> lower fitness = higher probably
  for(int i=0;i<populationSize;i++){
    fixedFitness[i]=maxFitness-population->getPopulation()[i].getFitness() +minFitness;
    fixedSumFitness+=fixedFitness[i];
  }

  mt19937 generator(random_device{}() );
  uniform_real_distribution<> dist(0, 1);
  float randNumber=dist(generator);


  for(int i=0;i<populationSize;i++){
    fixedFitness[i]=((float)fixedFitness[i])/((float)fixedSumFitness);

    if(randNumber>=currentFitness && randNumber<=currentFitness+fixedFitness[i]){
      free(fixedFitness);
      return i;
    }
    currentFitness+=fixedFitness[i];
  }

  free(fixedFitness);
  return -1;
}
