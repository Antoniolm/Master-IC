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
#include <iostream>
#include "reader.h"
#include "geneticAlgorithm/gaStandar.h"

using namespace std;

int main(void){

   //Reader *reader=new Reader("qapdata/chr12a.dat");
   //Reader *reader=new Reader("qapdata/bur26a.dat");
   Reader *reader=new Reader("qapdata/tai64c.dat");
   //Reader *reader=new Reader("qapdata/tai100b.dat");
   //Reader *reader=new Reader("qapdata/tai256c.dat");

   //GAStandar* GAlgorithmStandar=new GAStandar(2,reader->getProblemSize(),LAMARCKIAN);
   //GAStandar* GAlgorithmStandar=new GAStandar(2,reader->getProblemSize(),BALDWINIAN);
   GAStandar* GAlgorithmStandar=new GAStandar(400,reader->getProblemSize(),STANDAR);
   GAlgorithmStandar->execute(40,reader);

   delete reader;
   delete GAlgorithmStandar;

   return 0;

 }
