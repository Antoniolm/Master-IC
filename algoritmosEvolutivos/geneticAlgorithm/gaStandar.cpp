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

GAStandar::~GAStandar(){
  if(population!=0)
    delete population;
}

//************************************************//

void GAStandar::execute(){

  population=new Population(5);

  population->calculateFitness();

  while (population->getFitness() < 5) {

           selection();
           crossover();

           if (rand() % 100 < 10) {
               mutation();
           }

          population->calculateFitness();
  }

}


//************************************************//

void GAStandar::mutation(){

}

//************************************************//

void GAStandar::crossover(){

}

//************************************************//

void GAStandar::selection(){

}
