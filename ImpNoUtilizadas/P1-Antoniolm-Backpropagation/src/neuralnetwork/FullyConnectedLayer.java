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

import java.util.Random;
import neuralnetwork.activation.SigmoidActivation;

/**
 *
 * @author Antoniolm
 */
public class FullyConnectedLayer extends Layer{
        
    public FullyConnectedLayer(int n,int m){
        entradas=n;
        salidas=m;
        output=new double[salidas];
        input=new double[entradas];
        bias=new double[salidas];
        weights=new double[salidas][entradas];
        activation=new SigmoidActivation();
        
        deltaB=new double[salidas];
        deltaX=new double[entradas];
        deltaW=new double[salidas][entradas];
        delta=new double[salidas];
        
    }
    
    @Override
    public void init(){
        Random aleatorio = new Random(System.currentTimeMillis());
        
        for(int i=0;i<weights.length;i++)
            for(int j=0;j<weights[i].length;j++){
                weights[i][j] = 2* (aleatorio.nextFloat() - 0.5);
                deltaW[i][j] = 2* (aleatorio.nextFloat() - 0.5);
            }      
        
        //Init deltas
        for(int i=0;i<entradas;i++)
            deltaX[i]=0.0;
            
        for(int i=0;i<salidas;i++){
            deltaB[i]=0.0;
            delta[i]=0.0;
        }
        
    }
    
    @Override
    public double[] forward(double[] values) {
        double [] result=new double[10];
        
        input=values;
                
        for(int j=0;j<output.length;j++){
            double z=bias[j];
            for(int i=0;i<values.length;i++)
                z+=weights[j][i]*values[i];
            output[j]=activation.evaluate(z);
        }
        
        return output;
    }

    @Override
    public void backward(double[] error) {
        
        for(int j=0;j<salidas;j++){
            delta[j]=error[j]*activation.diff(output[j]);
            
            deltaB[j]=delta[j];
            
            for(int i=0;i<entradas;i++)
                deltaW[j][i]=delta[j]*input[i];
            
            for(int i=0;i<entradas;i++)
                deltaX[i]=dot(delta,weights[j]);
        }
        
    }
    
    public void update(double eta){
        for(int j=0;j<salidas;j++){
            bias[j]+=eta*delta[j];
            
            for(int i=0;i<entradas;i++)
                weights[j][i]+=eta*input[i]*delta[j];
        }
    }
    
    public double [] getDeltaX(){
        return deltaX;
    }
    
    public double dot(double [] x, double [] y){
        double dot=0;
        for(int i=0;i<x.length;i++)
            dot+=x[i]*y[i];
        
        return dot;
    }
    
    
}
