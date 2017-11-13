/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package neuralnetwork;

import java.util.Random;
import neuralnetwork.activation.SigmoidActivation;

/**
 *
 * @author LENOVO
 */
public class FullyConnectedLayer extends Layer{
    
    double [] deltaB;
    double [] deltaX;
    double [][] deltaW;
    
    public FullyConnectedLayer(int n,int m){
        entradas=n;
        salidas=m;
        bias=new double[salidas];
        weights=new double[28][28];
        activation=new SigmoidActivation();
        
        /*FIX SIZE */
        deltaB=new double[10];
        deltaX=new double[10];
        deltaW=new double[10][10];
        
    }
    
    @Override
    public void init(){
        Random aleatorio = new Random(System.currentTimeMillis());
        
        for(int i=0;i<weights.length;i++)
            for(int j=0;j<weights[i].length;j++){
                weights[i][j] = 2* (aleatorio.nextFloat() - 0.5);
                deltaW[i][j] = 2* (aleatorio.nextFloat() - 0.5);
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
        
        for(int j=0;j<10;j++){
            delta[j]=error[j]*activation.diff(output[j]);
            
            deltaB[j]=delta[j];
            
            for(int i=0;i<10;i++)
                deltaW[j][i]=delta[j]*input[i];
            
            for(int i=0;i<10;i++)
                deltaX[i]=dot(delta[j],weights[j]);
            
        }
        
    }
    
    public void update(double eta){
        for(int j=0;j<output.length;j++){
            bias[j]+=eta*delta[j];
            for(int i=0;i<input.length;i++)
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
