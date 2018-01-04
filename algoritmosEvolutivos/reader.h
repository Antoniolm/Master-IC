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

#include <string>
#include <fstream>
#include "matrix.h"

using namespace std;

class Reader{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Reader();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor  with parameters*/
  //////////////////////////////////////////////////////////////////////////
  Reader(string file);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Reader();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will read the file of the parameters
   *  \param file -> the name of the file that will be read
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void read(string file);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will convert to string the object
   *  \return -> the string with the information of the object
   */
  //////////////////////////////////////////////////////////////////////////
  string toString();

protected:

private:
  int sizeProblem;
  Matrix* distanceMatrix;
  Matrix* flowMatrix;

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will initialize the matrix of elements
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void initMatrix();

};
