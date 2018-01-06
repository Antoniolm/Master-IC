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

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <string>
#include <fstream>

using namespace std;

class Individual{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Individual();

  Individual(int numGenes);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Individual();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will initialize the individual parameters
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void init();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will calculate the fitness of the individual
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void calculateFitness();

  int * getGenes();
  string getChromosome();
  int getFitness();


protected:

private:
  int * genes;       // genes of the individul
  int nGenes;
  string chromosome; // solution of the individual
  int fitness;       // score of the individual


};

#endif
