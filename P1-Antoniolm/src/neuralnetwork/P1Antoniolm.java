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
        
        NeuralNetwork neuralNet=new NeuralNetwork();
        MNISTDatabase dataBase=new MNISTDatabase();
        
        int trainingImages[][][];
        int testImages[][][];
        
        int trainingLabels[];
        int testLabels[];
        //images = readImages("data/mnist/"+trainingImages);
        
        /////////////
        //TRAINING
        /////////////
        trainingImages = dataBase.readImages("data/mnist/train-images-idx3-ubyte.gz");

        //float normalizedImages[][][];
        //ArrayList<ArrayList<ArrayList<ArrayList<Float>>>> normalizedImages;
        //loop
        for(int i=0;i<10;i++){
            // Normalize image data
            float data[][] = dataBase.normalize(trainingImages[i]);
            //neuralNet.analyze(data);
            
            //////////////////
            //check result
            trainingLabels = readLabels("data/mnist/train-labels-idx1-ubyte.gz");
        }
        
        
        
        /////////////
        //TESTING
        /////////////

        testImages = dataBase.readImages("data/mnist/t10k-images-idx3-ubyte.gz");
        
        //loop
        for(int i=0;i<10;i++){
            // Normalize image data
            float data[][] = dataBase.normalize(trainingImages[i]);
            //neuralNet.analyze(data);
            
            ////////////////
            //check result
            testLabels = readLabels("data/mnist/t10k-labels-idx1-ubyte.gz");
            
        }
    }
    
}
