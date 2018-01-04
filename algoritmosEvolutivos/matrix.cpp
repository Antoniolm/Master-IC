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
#include "matrix.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Matrix::Matrix(){
  size=0;
  matrix=0;
}

//************************************************//

Matrix::Matrix(int sizeM){
  size=sizeM;

  if(size>0){

    matrix= (int**) malloc(size * sizeof(int*));

    for(int i=0;i<size;i++){
      matrix[i]=(int*) malloc(size * sizeof(int));
    }
  }


}

//************************************************//

Matrix::Matrix(int sizeM, ifstream & stream){
  size=sizeM;
  if(size>0){

    matrix= (int**) malloc(size * sizeof(int*));

    for(int i=0;i<size;i++){
      matrix[i]=(int*) malloc(size * sizeof(int));
    }
  }
  readMatrix(stream);

}

//************************************************//

Matrix::~Matrix(){
  if(size>0){
    for(int i=0;i<size;i++){
      free(matrix[i]);
    }

    free(matrix);
  }
}


//************************************************//
void Matrix::readMatrix(ifstream & stream){
  if(size>0 && matrix!=0){
      cout<< "Was created"<<endl;


  }
}

//************************************************//


void Matrix::setSize(int sizeM){
  size=sizeM;
}

//************************************************//

int Matrix::getSize(){
  return size;
}

//************************************************//

string Matrix::toString(){
  string result;

  for(int i=0;i<size;i++){
    for(int j=0;i<size;j++){
      result.append(to_string(matrix[i][j]).append(" "));
    }
    result.append("\n");
  }
  return result;
}
