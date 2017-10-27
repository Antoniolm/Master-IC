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
    
    public FeedForwardNetwork(){
        layers=new ArrayList<Layer>();
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
        
        return 0.0d;
    }
}
