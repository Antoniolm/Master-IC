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
package neuralnetwork;

import neuralnetwork.activation.Activation;
import java.util.ArrayList;

/**
 *
 * @author LENOVO
 */
public abstract class Layer {
    double [][] weights;
    double [] bias;
    int entradas,salidas;
    double [] output;
    double [] input;
    double [] delta;
    double [] deltaB;
    double [] deltaX;
    double [][] deltaW;
    
    Activation activation;
        
    public abstract void init();
    public abstract double [] forward(double [] values);
    public abstract void backward(double [] error);
    public abstract void update(double eta);
    
           
}
