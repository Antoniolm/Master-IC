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

import static java.lang.Math.log;
import neuralnetwork.activation.SigmoidActivation;
import neuralnetwork.activation.Activation;
import java.util.ArrayList;

/**
 *
 * @author LENOVO
 */
public class FeedForwardNetwork extends Layer{
    ArrayList<FullyConnectedLayer> layers;
    double [][] deltaMatrix;
    double eta;
    
    Activation activation;
    
    public FeedForwardNetwork(int n,int m){
        layers=new ArrayList<FullyConnectedLayer>();
        deltaMatrix=new double[layers.size()][20];
        eta=0.06d;
        activation=new SigmoidActivation();
        //add layers
        layers.add(new FullyConnectedLayer(28*28,10));
        layers.add(new FullyConnectedLayer(10,10));
    }
    
    @Override
    public void init(){
        for(int i=0;i<layers.size();i++)
            layers.get(i).init();
    }
    
    public double [] forward(double [] x){
        output=x;
        for(int i=0;i<layers.size();i++){
            output=layers.get(i).forward(output);
        }
        return output;
    }
    
     public void backward(double [] error){
        
        for(int j=layers.size();j>=0;j--){
            layers.get(j).backward(error);
            error=layers.get(j).getDeltaX();
            //guardar deltas en delta[][];
        }
    }
    
     public void update(double eta) {
         for(int j=0;j<layers.size();j++){
            layers.get(j).update(eta);
        }
         
     }
     
     
    public void train(float [][]data,int label,double eta){
        forward(convertImage(data)); //process image 
        double [] error=crossEntropy(label,output);
        backward(error);
        update(eta);
    } 
    
    
   public double [] convertImage(float [][]data ){
       double [] result=new double[data.length*data[0].length];
      
       for(int i=0;i<data.length;i++){
           for(int j=0;j<data[i].length;j++)
               result[i*data.length +j]=data[i][j];
       }
       return result;
   }
    
    //todos a 0 excpeto el que sea verdadero a 1 
    public double [] crossEntropy(int valueC,double [] output){
        double [] error=new double[output.length];
        
        int [] target=new int[10];
        for(int i=0;i<target.length;i++)
            if(valueC==i) target[i]=1;
            else target[i]=0;
        
        for(int i=0;i<output.length;i++)
            error[i]=-target[i] * log(output[i]) - (1.0-target[i])*log(1.0-output[i]);
        
        return error;
    }
    
    public double dot(double [] x, double [] y){
        double dot=0;
        for(int i=0;i<x.length;i++)
            dot+=x[i]*y[i];
        
        return dot;
    }
}
