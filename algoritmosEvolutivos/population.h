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
#include "matrix.h"
#include "geneticAlgorithm/geneticAlgorithm.h"

using namespace std;

class Individual;
class Population{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Population();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters */
  //////////////////////////////////////////////////////////////////////////
  Population(int sizeP,int sizeGenes);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Population();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will make a local search to obtain the enhanced genes
   *  \param sizeP -> the size of the population
   *  \param sizeGenes -> the size of the genes of each individual
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void init(int sizeP,int sizeGenes);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will calculate the fitness of the population
   *  \param flowMatrix -> the flow matrix of the problem
   *  \param distanceMatrix -> the distance matrix of the problem
   *  \param type -> the type of the genetic algorithm
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void calculateFitness(Matrix* distanceMatrix,Matrix* flowMatrix,GAType type);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the fitness of the population
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  int getFitness();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will return the list of individuals
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  Individual* getPopulation();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will convert the population to string
   *  \return the converted population on String
   */
  //////////////////////////////////////////////////////////////////////////
  string toString();


protected:

private:
  int size;
  Individual* population;
  int fitness;


};

#endif
