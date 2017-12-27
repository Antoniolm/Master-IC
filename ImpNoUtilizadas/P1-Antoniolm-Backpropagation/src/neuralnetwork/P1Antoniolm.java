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

import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import mnist.MNISTDatabase;
import static mnist.MNISTDatabase.normalize;
import static mnist.MNISTDatabase.readImages;
import static mnist.MNISTDatabase.readLabels;
import static mnist.MNISTDatabase.toString;

/**
 *
 * @author Antoniolm
 */
public class P1Antoniolm {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        MNISTDatabase dataBase=new MNISTDatabase();
        FeedForwardNetwork neuralNet=new FeedForwardNetwork(0,0);
        neuralNet.init();
        
        int trainingImages[][][];
        int testImages[][][];
        
        int trainingLabels[];
        int testLabels[];
        
        /////////////
        //TRAINING
        /////////////
        trainingImages = dataBase.readImages("data/mnist/train-images-idx3-ubyte.gz");
        trainingLabels = dataBase.readLabels("data/mnist/train-labels-idx1-ubyte.gz");

        int errors=0;
        double [] result=new double[10];
        System.out.println("-- Training --");
       
        //loop
        for(int i=0;i<trainingImages.length;i++){
            // Normalize image data
            float data[][] = dataBase.normalize(trainingImages[i]);
            
            result=neuralNet.train(data, trainingLabels[i], 0.06);
            DecimalFormat df = new DecimalFormat();
            df.setMaximumFractionDigits(2);
            
            for(int j=0;j<result.length;j++){
                System.out.print(df.format(result[j])+",");   
            }
            System.out.print("-->"+trainingLabels[i]);
            System.out.println(" ");
                        
        }
                
        System.out.println("Errors of training -> "+errors+ "/"+trainingImages.length);
                
        /////////////
        //TESTING
        /////////////
       /* System.out.println("-- Model --");
        trainingImages=null;trainingLabels=null;
        testImages = dataBase.readImages("data/mnist/t10k-images-idx3-ubyte.gz");
        testLabels = dataBase.readLabels("data/mnist/t10k-labels-idx1-ubyte.gz");
        result=new double[10];
        
        //loop
        for(int i=0;i<testImages.length;i++){
            // Normalize image data
            float data[][] = dataBase.normalize(trainingImages[i]);
            
            result=neuralNet.forward(neuralNet.convertImage(data));
        }*/
    }
    
}
