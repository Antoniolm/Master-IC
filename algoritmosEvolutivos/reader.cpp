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
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Reader::Reader(){
  sizeProblem=0;
}

//************************************************//

Reader::Reader(string file){
  sizeProblem=0;
  read(file);
}

//************************************************//

Reader::~Reader(){
  if(sizeProblem>0){
    delete distanceMatrix;
    delete flowMatrix;
  }

}

//************************************************//

void Reader::read(string file){
  ifstream inputfile;
  string strLine;
  string auxStr;

  inputfile.open(file.c_str());

  getline( inputfile, strLine );
  sizeProblem=atoi(strLine.c_str());

  initMatrix();

  getline( inputfile, strLine ); //skip empty line
  distanceMatrix->readMatrix(inputfile);

  getline( inputfile, strLine ); //skip empty line
  flowMatrix->readMatrix(inputfile);

  inputfile.close();
}


//************************************************//
string Reader::toString(){
  string result;
  result.append(to_string(sizeProblem).append("\r\n"));
  result.append(distanceMatrix->toString());
  result.append(flowMatrix->toString());
  return result;
}

//************************************************//

Matrix * Reader::getDistanceMatrix(){
  return distanceMatrix;
}

//************************************************//

Matrix * Reader::getFlowMatrix(){
  return flowMatrix;
}

//************************************************//
// PRIVATE METHODS
//************************************************//
void Reader::initMatrix(){
  if(sizeProblem>0){

    distanceMatrix=new Matrix(sizeProblem);
    flowMatrix=new Matrix(sizeProblem);
  }

}
