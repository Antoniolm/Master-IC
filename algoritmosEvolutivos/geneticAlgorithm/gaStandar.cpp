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

  cout<< population->toString();

  population->calculateFitness(reader->getFlowMatrix(),reader->getDistanceMatrix());

  for(int i=0;i<populationSize;i++)
    selection();
  //for(int i=0;i)
  //while (population->getFitness() < 5) {
    // optimizacion local -> no estandar solo los otros dos

           /*selection();
           crossover(new Individual(populationSize),new Individual(populationSize)); // suele ser mitad y mitad
                        // Cambiar por los reales selection
                        //
                        //

           // mutation for each individual
          mutation(); // intercambiar dos genes de posición
                      // recorro el cromosoma  0.05 ( sea por proporción del problema ) por cada gen y si es 0.05 lo muto sino no


          population->calculateFitness();*/
  //}

}

//************************************************//

void GAStandar::mutation(){
  /*Individual* individual = population->getPopulation();
  int secondIndex;

  for(int j=0;j<populationSize;j++){
      for(int i=0;i<populationSize;i++){
        if (rand() % 100 < 5) {

          do{
            secondIndex=rand()%populationSize;
          }while(secondIndex==i);

          individual[j].swapGenes(i,secondIndex);

        }
      }
  }*/
}

//************************************************//

Individual* GAStandar::crossover(Individual* ind1,Individual* ind2){
  Individual* resultChild=new Individual[2];
  /*resultChild[0].setNGenes(populationSize); resultChild[0].init();
  resultChild[1].setNGenes(populationSize); resultChild[1].init();

  int* genes1=ind1->getGenes();
  int* genes2=ind2->getGenes();

  resultChild[0].crossover(populationSize/2,genes1,genes2);
  resultChild[1].crossover(populationSize/2,genes2,genes1);
  */
  return resultChild;
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
