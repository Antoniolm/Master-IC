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

#ifndef POPULATION_H
#define POPULATION_H

#include <string>
#include <fstream>
#include "individual.h"

using namespace std;

class Population{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Population();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters*/
  //////////////////////////////////////////////////////////////////////////
  Population(int sizeP);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Population();

  void init(int sizeP);

  void calculateFitness();

  int getFitness();

  Individual* getPopulation();


protected:

private:
  int size;
  Individual* population;
  int fitness;


};

#endif
