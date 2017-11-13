/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
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
    double [][] delta;
    double eta;
    
    Activation activation;
    
    public FeedForwardNetwork(int n,int m){
        layers=new ArrayList<FullyConnectedLayer>();
        delta=new double[layers.size()][20];
        
        activation=new SigmoidActivation();
        //add layers
        layers.add(new FullyConnectedLayer(10,10));
        layers.add(new FullyConnectedLayer(28*28,10));
        
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
        
        for(int j=0;j<layers.size();j++){
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
