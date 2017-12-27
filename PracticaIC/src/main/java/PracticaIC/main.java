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

package PracticaIC;

import PracticaIC.NeuralNetwork.NNConvolutional;
import PracticaIC.NeuralNetwork.NNMultiLayer;
import PracticaIC.NeuralNetwork.NNSingleLayer;
import PracticaIC.NeuralNetwork.NeuralNetwork;
import org.deeplearning4j.datasets.fetchers.MnistDataFetcher;
import org.deeplearning4j.datasets.iterator.impl.MnistDataSetIterator;
import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.dataset.DataSet;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.io.PrintWriter;

public class main {
    private static Logger log = LoggerFactory.getLogger(main.class);

    public static void main(String[] args) throws Exception {
        final int input = 28*28;
        int output = 10;
        int blockImage = 64;
        int seedNumber = 74;
        double trainInitTime, trainTime;
        double testInitTime, testTime;

        DataSetIterator trainingDataSet = new MnistDataSetIterator(blockImage, true, seedNumber);
        DataSetIterator testDataSet = new MnistDataSetIterator(blockImage, false, seedNumber);
        //DataSetIterator trainingDataSet = new MnistDataSetIterator(blockImage, 60000,false,true,false,seedNumber);
        //DataSetIterator testDataSet = new MnistDataSetIterator(blockImage, 10000,false,false,false,seedNumber);
        //System.out.println("Examples"+trainingDataSet.totalExamples());
        //System.out.println("Examples"+testDataSet.totalExamples());

        System.out.println("Building model....");
        //NeuralNetwork network=new NNSingleLayer(input,output);
        //NeuralNetwork network=new NNMultiLayer(input,output);
        NeuralNetwork network=new NNConvolutional(input,output);

        ////////////////////////////
        // Training neurol network
        ////////////////////////////
        trainInitTime=System.nanoTime();
        System.out.println("Train model....");
        network.train(trainingDataSet,40);
        network.showResults();

        trainTime=(System.nanoTime()-trainInitTime)/1000000000.0;

        ////////////////////////////
        // Testing neuronal network
        ////////////////////////////
        testInitTime=System.nanoTime();

        System.out.println("Evaluate model....");
        network.evaluate(testDataSet);
        network.showResults();

        testTime=(System.nanoTime()-testInitTime)/1000000000.0;
        //labelsString(); // to extract the file data

        System.out.println("<Train time = "+String.format( "%.2f", trainTime)+">");
        System.out.println("<Test time = "+String.format( "%.2f", testTime )+">");
        System.out.println("<Total time = "+String.format( "%.2f",(trainTime+testTime))+">");
    }

    /**
     * Create a file with all the outputs of the mnist test
     * @throws IOException
     */
    public static void labelsString() throws IOException {
        DataSetIterator testDataSet = new MnistDataSetIterator(1, MnistDataFetcher.NUM_EXAMPLES_TEST, false, false, false, 133);
        String currentOuput="";
        PrintWriter writer = new PrintWriter("outPutMnist.txt", "UTF-8");

        while (testDataSet.hasNext()) {
            DataSet next = testDataSet.next();
            INDArray array=next.getLabels();

            for(int j=0;j<array.length();j++){
                if(array.getInt(j)==1)
                    currentOuput+=j+"";
            }

        }

        writer.println(currentOuput);
        writer.close();
    }
}
