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

#ifndef GASTANDAR_H
#define GASTANDAR_H

#include <string>
#include <fstream>
#include "geneticAlgorithm.h"
#include "../population.h"
#include "../individual.h"

using namespace std;

class GAStandar : public GeneticAlgorithm{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  GAStandar();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters*/
  //////////////////////////////////////////////////////////////////////////
  GAStandar(int popuSize);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~GAStandar();

  void execute();
  void mutation();
  Individual* crossover(Individual* ind1,Individual* ind2);
  void selection();

protected:

private:
  Population* population;


};

#endif
