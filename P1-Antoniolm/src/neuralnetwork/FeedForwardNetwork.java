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
    
    public ArrayList<Double> forward(ArrayList<Double> x){
        ArrayList<Double> result=x;
        for(int i=0;i<layers.size();i++){
            result=layers.get(i).forward(result);
        }
        return result;
    }
}
