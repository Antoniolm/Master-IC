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
#include "geneticAlgorithm/geneticAlgorithm.h"

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
  /** Copy Constructor */
  //////////////////////////////////////////////////////////////////////////
  Individual(Individual *individual);

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
   *  It will calculate the basic fitness of the individual
   *  \param flowMatrix -> the flow matrix of the problem
   *  \param distanceMatrix -> the distance matrix of the problem
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void calculateBasicFitness(Matrix* flowMatrix,Matrix* distanceMatrix);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will adjusted the basic fitness of the individual
   *  \param flowMatrix -> the flow matrix of the problem
   *  \param distanceMatrix -> the distance matrix of the problem
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void recalculateBasicFitness(int i, int j, Matrix* flowMatrix,Matrix* distanceMatrix, int* oldGenes);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will calculate the fitness of the individual using the type
   *  of the algorithm
   *  \param flowMatrix -> the flow matrix of the problem
   *  \param distanceMatrix -> the distance matrix of the problem
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void calculateFitness(Matrix* flowMatrix,Matrix* distanceMatrix,GAType type);

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
   *  It will return the current fitness of the individual
   *  \return int
   */
  //////////////////////////////////////////////////////////////////////////
  int getFitness();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the current enhanced fitness of the individual
   *  \return int
   */
  //////////////////////////////////////////////////////////////////////////
  int getEnhancedFitness();

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
   *  \param cutOff1 -> first limit of the first parent
   *  \param cutOff2 -> second limit of the first parent
   *  \param genesP1 -> Genes of the first parent
   *  \param genesP2 -> Genes of the second parent
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void crossover(int cutOff1,int cutOff2, int* genesP1, int* genesP2);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will convert the individual to string
   *  \return the converted individual on String
   */
  //////////////////////////////////////////////////////////////////////////
  string toString();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will make a local search to obtain the enhanced genes
   *  \param flowMatrix -> the flow matrix of the problem
   *  \param distanceMatrix -> the distance matrix of the problem
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void localSearch(Matrix* flowMatrix,Matrix* distanceMatrix);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will copy the information of the individual parameters to the individual
   *  \param individual -> the copied individual
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void copy(Individual *individual);

protected:

private:
  int * genes;       // genes of the individul
  int * enhancedGenes;
  int nGenes;
  int fitness;       // score of the individual
  int enhancedFitness;

};

#endif
