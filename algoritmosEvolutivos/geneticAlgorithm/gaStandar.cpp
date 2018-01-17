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
  if(population!=0)
    delete population;
}

//************************************************//

void GAStandar::execute(){

  population=new Population(populationSize);

  population->calculateFitness();

  while (population->getFitness() < 5) {
    // optimizacion local -> no estandar solo los otros dos

           selection();
           crossover(); // suele ser mitad y mitad
                        //
                        //
                        //

           // hacer la mutación individoo a individuo selecciono
           if (rand() % 100 < 10) {
               mutation(); // intercambiar dos genes de posición
                           // recorro el cromosoma  0.05 ( sea por proporción del problema ) por cada gen y si es 0.05 lo muto sino no

           }

          population->calculateFitness();
  }

}

//************************************************//

void GAStandar::mutation(){
  Individual* individual = population.getPopulation();
  int firstIndex,secondIndex;

  for(int j=0;j<populationSize;j++){
      for(int i=0;i<populationSize;i++){
        if (rand() % 100 < 5) {

          do{
            secondIndex=rand()%populationSize;
          }while(secondIndex==i);

          individual[j].swapGenes(i,secondIndex)

        }
      }
  }
}

//************************************************//

void GAStandar::crossover(){

}

//************************************************//

void GAStandar::selection(){

}
