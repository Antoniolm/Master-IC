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

import PracticaIC.NeuralNetwork.NNSingleLayer;
import PracticaIC.NeuralNetwork.NeuralNetwork;
import org.deeplearning4j.datasets.fetchers.MnistDataFetcher;
import org.deeplearning4j.datasets.iterator.impl.MnistDataSetIterator;
import org.deeplearning4j.eval.Evaluation;
import org.deeplearning4j.nn.api.OptimizationAlgorithm;
import org.deeplearning4j.nn.conf.MultiLayerConfiguration;
import org.deeplearning4j.nn.conf.NeuralNetConfiguration;
import org.deeplearning4j.nn.conf.Updater;
import org.deeplearning4j.nn.conf.layers.DenseLayer;
import org.deeplearning4j.nn.conf.layers.OutputLayer;
import org.deeplearning4j.nn.multilayer.MultiLayerNetwork;
import org.deeplearning4j.nn.weights.WeightInit;
import org.deeplearning4j.optimize.listeners.ScoreIterationListener;
import org.nd4j.linalg.activations.Activation;
import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.dataset.DataSet;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;
import org.nd4j.linalg.lossfunctions.LossFunctions;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * Created by LENOVO on 08/11/2017.
 */
public class main {
    private static Logger log = LoggerFactory.getLogger(main.class);

    public static void main(String[] args) throws Exception {
        //number of rows and columns in the input pictures
        final int numRows = 28;
        final int numColumns = 28;
        int outputNum = 10; // number of output classes
        int batchSize = 128; // batch size for each epoch
        int rngSeed = 123; // random number seed for reproducibility
        int numEpochs = 15; // number of epochs to perform

        //Get the DataSetIterators:
        //MnistDataFetcher https://github.com/deeplearning4j/deeplearning4j/blob/master/deeplearning4j-core/src/main/java/org/deeplearning4j/datasets/fetchers/MnistDataFetcher.java
        //MnistFetcher.gunzipFile();
        /*MnistDataFetcher prueba= new MnistDataFetcher(false,true,false,rngSeed);
        prueba.reset();
        MnistDataFetcher pruebaTest= new MnistDataFetcher(false,false,false,rngSeed);
        pruebaTest.reset();*/
        //DataSetIterator mnistTrain = new MnistDataSetIterator(batchSize, true, rngSeed);
        //DataSetIterator mnistTest = new MnistDataSetIterator(batchSize, false, rngSeed);
        DataSetIterator mnistTrain = new MnistDataSetIterator(batchSize, MnistDataFetcher.NUM_EXAMPLES,false,true,false,rngSeed);
        //System.out.println("Examples"+mnistTrain.totalExamples());
        DataSetIterator mnistTest = new MnistDataSetIterator(batchSize, MnistDataFetcher.NUM_EXAMPLES_TEST,false,false,false,rngSeed);

        System.out.println("Building model....");
        NeuralNetwork network=new NNSingleLayer(rngSeed,numRows,numColumns,outputNum);


        log.info("Training");
        System.out.println("Train model....");
        /*for(int i=0;i<numEpochs;i++) {
            network.getNetwork().fit(mnistTrain);
        }*/

        Evaluation eval = new Evaluation(outputNum); //create an evaluation object with 10 possible classes
        while(mnistTrain.hasNext()) {
            DataSet next = mnistTrain.next();
            INDArray output = network.getNetwork().output(next.getFeatureMatrix()); //get the networks prediction
            eval.eval(next.getLabels(), output); //check the prediction against the true class
            network.getNetwork().fit(next);
        }
        System.out.println(eval.stats());

        System.out.println("Evaluate model....");
        eval = new Evaluation(outputNum); //create an evaluation object with 10 possible classes

        while(mnistTest.hasNext()){
            DataSet next = mnistTest.next();
            INDArray output = network.getNetwork().output(next.getFeatureMatrix()); //get the networks prediction
            eval.eval(next.getLabels(), output); //check the prediction against the true class
        }

        System.out.println(eval.stats());
        System.out.println("****************Example finished********************");
    }
}
