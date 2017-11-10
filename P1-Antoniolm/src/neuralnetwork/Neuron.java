/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package neuralnetwork;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author LENOVO
 */
public class Neuron {
    float weights[][];
    double bias;
    boolean activated;
    
    public Neuron(){
        activated=false;
        bias=0.5;
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
        if(value > bias)
            activated=true;
        return value;
    }
    
    public void adjustWeights(boolean success,float testImage[][]){
        for(int i=0;i<weights.length;i++){
            for(int j=0;j<weights[i].length;j++){
                if(activated && !success)
                    weights[i][j]-=testImage[i][j];
                
                if(!activated && success)
                    weights[i][j]+=testImage[i][j];
                
                if(weights[i][j]<0.0) weights[i][j]=0;
                if(weights[i][j]>1.0) weights[i][j]=1;
            }
        }
    }
    
    public boolean getActivated(){
        return activated;
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
