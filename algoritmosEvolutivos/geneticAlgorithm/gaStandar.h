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
#include <random>
#include "geneticAlgorithm.h"
#include "../reader.h"

using namespace std;

class Population;
class GAStandar : public GeneticAlgorithm{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  GAStandar();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters*/
  //////////////////////////////////////////////////////////////////////////
  GAStandar(int popuSize,int geneSize,GAType aType);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~GAStandar();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will execute the genetic algorithm
   *  \param reader -> the reader with the current problem to solve
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void execute(Reader* reader);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will mutate the population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void mutation();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will crossover the population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void crossover();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will select the parent of the new population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void selection();

protected:

private:
  Population* population;
  int* currentSelection;
  GAType type;

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will select a individual using the roullete selection
   *  \return int -> The index of the selected individual
   */
  //////////////////////////////////////////////////////////////////////////
  int roulleteSelection();


};

#endif
