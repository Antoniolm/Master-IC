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
 * @author Antoniolm
 */
public class NeuralNetwork {
    int internResult;
    ArrayList<Neuron> neurons;
    
    public NeuralNetwork(){
       neurons=new ArrayList<Neuron>(); 
    }
    
    public void analyze(float data[][]){
        ArrayList<Double> results=new ArrayList<Double>();
            
        for(int i=0;i<10;i++){
            results.add(neurons.get(i).processImage(data)); 
        }    
         
        double maxValue=-1;
        internResult=-1;
        
        for(int i=0;i<results.size();i++){
            if(maxValue<results.get(i)){
                maxValue=results.get(i);
                internResult=i;
            }
        }
    }
    
    public boolean check(int value){
        boolean result=false;
        
        if(value==internResult)
            result=true;
       
        return result;
    }
    
    
    
    
}
