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
import java.util.Random;

/**
 *
 * @author Antoniolm
 */
public class Neuron {
    float weights[][];
    double bias;
    boolean activated;
    
    public Neuron(){
        activated=false;
        weights=new float[28][28];
        
        Random aleatorio = new Random(System.currentTimeMillis());
        
        for(int i=0;i<weights.length;i++)
            for(int j=0;j<weights[i].length;j++){
                weights[i][j] = aleatorio.nextFloat();
            }
    }
    
    public double processImage(float testImage[][]){
        activated=false;
        float value=0.0f;
        
        for(int i=0;i<weights.length;i++){
            for(int j=0;j<weights[i].length;j++){
                value+=weights[i][j]*testImage[i][j];
            }
        }
        if(value > 2)
            activated=true;
        return value;
    }
    
    public void adjustWeights(boolean success,float testImage[][]){
        for(int i=0;i<weights.length;i++){
            for(int j=0;j<weights[i].length;j++){
                if(activated && !success)
                    weights[i][j]-=testImage[i][j]*0.3;
                
                if(!activated && success)
                    weights[i][j]+=testImage[i][j]*0.3;
                
                if(weights[i][j]<0.0) weights[i][j]=0;
                if(weights[i][j]>1.0) weights[i][j]=1;
            }
        }
    }
    
    public void print(){
        for(int i=0;i<weights.length;i++){
            for(int j=0;j<weights[i].length;j++){
                System.out.print(weights[i][j]+" ");
            }
            System.out.println("");
        }
    }
            
}
