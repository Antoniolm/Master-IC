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

#ifndef GENERIC_ALGORITHM_H
#define GENERIC_ALGORITHM_H

#include <string>
#include <fstream>
#include "../reader.h"

using namespace std;
enum GAType { STANDAR, BALDWINIAN, LAMARCKIAN };

class GeneticAlgorithm{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~GeneticAlgorithm();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will execute the genetic algorithm
   *  \param reader -> the reader with the current problem to solve
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  virtual void execute(Reader* reader)=0;

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will mutate the population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  virtual void mutation()=0;

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will crossover the population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  virtual void crossover()=0;

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will select the parent of the new population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  virtual void selection()=0;

protected:
  int populationSize;
  int geneSize;

private:

};

#endif
