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
#include <cstdlib>
#include "matrix.h"

using namespace std;

class Individual{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Individual();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters */
  //////////////////////////////////////////////////////////////////////////
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
  void calculateFitness(Matrix* flowMatrix,Matrix* distanceMatrix);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will swap the value of to position of the genes
   *  \param firstIndex -> the first position for swapping
   *  \param secondIndex -> the second position for swapping
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void swapGenes(int firstIndex, int secondIndex);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the current genes of the individual
   *  \return int*
   */
  //////////////////////////////////////////////////////////////////////////
  int * getGenes();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the current chromosome of the individual
   *  \return string
   */
  //////////////////////////////////////////////////////////////////////////
  string getChromosome();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the current fitness of the individual
   *  \return int
   */
  //////////////////////////////////////////////////////////////////////////
  int getFitness();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will set the number of genes of the individual
   *  \param size -> the number of genes
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void setNGenes(int size);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will divide the genes
   *  \param size -> the number of genes
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void crossover(int firstsection, int* genesP1, int* genesP2);

  string toString();

protected:

private:
  int * genes;       // genes of the individul
  int nGenes;
  string chromosome; // solution of the individual
  int fitness;       // score of the individual


};

#endif
