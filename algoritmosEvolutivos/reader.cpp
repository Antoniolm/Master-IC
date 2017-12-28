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
#include "reader.h"
#include <iostream>

using namespace std;

Reader::Reader(){
  sizeProblem=5;
}

//************************************************//

Reader::~Reader(){
  if(sizeProblem!=0){
    for(int i=0;i<sizeProblem;i++){
      free(distanceMatrix[i]);
      free(flowMatrix[i]);
    }

    free(distanceMatrix);
    free(flowMatrix);
  }

}

void Reader::init(){
  if(sizeProblem!=0){

    distanceMatrix= (int**) malloc(sizeProblem * sizeof(int*));
    flowMatrix= (int**) malloc(sizeProblem * sizeof(int*));

    for(int i=0;i<sizeProblem;i++){
      distanceMatrix[i]=(int*) malloc(sizeProblem * sizeof(int));
      flowMatrix[i]=(int*) malloc(sizeProblem * sizeof(int));
    }
  }
}

//************************************************//

void Reader::read(string file){

}
