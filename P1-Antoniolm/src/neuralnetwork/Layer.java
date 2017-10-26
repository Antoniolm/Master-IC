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

import java.util.ArrayList;

/**
 *
 * @author LENOVO
 */
public class Layer {
    ArrayList<ArrayList<Double> > matrixWeight;
    ArrayList<Double> vectorBias;
    int entradas,salidas;
    
    Activation activation;
    
    public Layer(int n,int m){
        entradas=n;
        salidas=m;
        activation=new SigmoidActivation();
    }
    
    public double forward(ArrayList<Double> values){
        Double result;
        ArrayList<Double> resultArr=new ArrayList<Double>();
        
        for(int j=0;j<salidas;j++){
            result=vectorBias.get(j);
            for(int i=0;i<entradas;i++){
                result+=matrixWeight.get(j).get(i)*values.get(i);
            }
            resultArr.add(activation.evaluate(result));
        }
        return 0.0d;
    }
           
}
