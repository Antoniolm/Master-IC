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
        layers.add(new FullyConnectedLayer(n,m));
        layers.add(new FullyConnectedLayer(n,m));
        
    }
    
    public double [] forward(double [] x){
        double [] result=x;
        for(int i=0;i<layers.size();i++){
            result=layers.get(i).forward(result);
        }
        return result;
    }
    
     public void backward(double [] error){
        
        for(int j=0;j<layers.size();j++){
            layers.get(j).backward(error);
            error=layers.get(j).getDeltaX();
        }
    }
    
     public void update(double eta) {
         for(int j=0;j<layers.size();j++){
            layers.get(j).update(eta);
        }
         
     }
     
     
    public void train(float [][]data,int label,double eta){
        forward(data[][]); //process image 
        double [] error=crossEntropy(label,output);
        backward(error);
        update(eta);
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
    
    public double [] crossEntropy(int target,double [] output){
        double [] error=new double[output.length];
        for(int i=0;i<output.length;i++)
            error[i]=-target * log(output[i]) - (1.0-target)*log(1.0-output[i]);
        
        return error;
    }
    
    public double dot(double [] x, double [] y){
        double dot=0;
        for(int i=0;i<x.length;i++)
            dot+=x[i]*y[i];
        
        return dot;
    }
}
