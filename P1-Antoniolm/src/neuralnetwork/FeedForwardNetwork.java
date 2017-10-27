/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package neuralnetwork;

import java.util.ArrayList;

/**
 *
 * @author LENOVO
 */
public class FeedForwardNetwork {
    ArrayList<Layer> layers;
    double [][] delta;
    
    Activation activation;
    
    public FeedForwardNetwork(){
        layers=new ArrayList<Layer>();
        delta=new double[layers.size()][20];
        
        activation=new SigmoidActivation();
        //add layers
    }
    
    public double [] forward(double [] x){
        double [] result=x;
        for(int i=0;i<layers.size();i++){
            result=layers.get(i).forward(result);
        }
        return result;
    }
    
    public double SSE (double [][][]data, int [] target){
        double error=0;
        int count=0;
        double [] output=new double[data.length];
        
        for(int k=0;k<data.length;k++){
            //output=forward(data[k]);
            for(int i=0;i<output.length;i++){
                error+=Math.pow(target[k]-output[i],2);
            }
        }
        return error;
    }
    
    public double MSE(double [][][]data, int [] target){
        return SSE(data,target)/data.length;
    }
    
    public double [] error(int [] target, double [] output){
        double [] result= new double[output.length];
        
        for( int i=0;i<output.length;i++)
            result[i]=(target[i]-output[i]);
        
        return result;
    }
    
    public void backward(double [] error){
        int sizeLayer= layers.size();
        
        for(int j=0;j<error.length;j++){
            //delta[sizeLayer][j]=error[j]* activation.diff(layers[sizeLayer])
        }
        
        for(int k=sizeLayer-1;k>0;k--){
            for(int j=0;j<layers.get(k).getOutput().length;j++){
                //error[k][j] = dot(layer[k+1].w[j], delta[k+1][j]);
                //delta[k][j] = error[k][j] * activation.diff(layer[k].z[j]);
            }
        }      
    }
    
    public void update(double eta){
        
        /*for(int k=0;k<layers.size();k++){
            for(int j=0;j<layers.get(k).getOutput().length;j++){
                //layers.get(k).b[j] += eta * delta[k][j];
                for(int i=0;i<layers.get(k).getInput().length;i++)
                    //layers.get(k).w[j][i] += eta * layers[k].input[i] * delta[k][j];
            //}
        //}*/
    }
    
    public double dot(double [] x, double [] y){
        double dot=0;
        for(int i=0;i<x.length;i++)
            dot+=x[i]*y[i];
        
        return dot;
    }
}
