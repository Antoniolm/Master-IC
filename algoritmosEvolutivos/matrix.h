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

using namespace std;

class Matrix{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Matrix();

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters */
  //////////////////////////////////////////////////////////////////////////
  Matrix(int sizeM);

  //////////////////////////////////////////////////////////////////////////
  /** Constructor with parameters */
  //////////////////////////////////////////////////////////////////////////
  Matrix(int sizeM, ifstream & stream);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Matrix();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will read the data of the matrix
   *  \param stream -> stream with the data of the matrix
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void readMatrix(ifstream & stream);

  void setSize(int sizeM);
  int getSize();

  string toString();

protected:

private:
  int** matrix;
  int size;

};
