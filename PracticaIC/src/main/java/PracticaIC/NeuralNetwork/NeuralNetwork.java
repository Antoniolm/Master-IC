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

package PracticaIC.NeuralNetwork;

import org.deeplearning4j.datasets.fetchers.MnistDataFetcher;
import org.deeplearning4j.datasets.iterator.impl.MnistDataSetIterator;
import org.deeplearning4j.eval.Evaluation;
import org.deeplearning4j.nn.multilayer.MultiLayerNetwork;
import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.dataset.DataSet;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;

import java.io.IOException;
import java.io.PrintWriter;

public abstract class NeuralNetwork {
    protected MultiLayerNetwork network;
    Evaluation evaluation;
    int output;
    int input;

    /**
     * Train the neurol network
     * @param dataSetIt
     */
    public void train(DataSetIterator dataSetIt, int epoch){
        for (int i =0;i<epoch;i++) {
            evaluation = new Evaluation(output);
            while (dataSetIt.hasNext()) {
                DataSet next = dataSetIt.next();
                INDArray output = network.output(next.getFeatureMatrix());
                evaluation.eval(next.getLabels(), output);
                network.fit(next);
            }
            dataSetIt.reset();
            System.out.println("Epoch -("+ (i+1) +"/"+epoch+")");
        }
    }

    /**
     * Show the result of the last evaluation
     */
    public void showResults(){
        if(evaluation != null)
            System.out.println(evaluation.stats());
        else
            System.out.println("You need train or evaluate the NN to have results");
    }

    /**
     * Evaluate the dataSetIt
     */
    public void evaluate(DataSetIterator dataSetIt) throws IOException {
        evaluation = new Evaluation(output);
        String currentOutputString="";

        while(dataSetIt.hasNext()) {
            DataSet next = dataSetIt.next();
            INDArray output = network.output(next.getFeatureMatrix());

            for(int i=0;i<output.rows();i++) {
                INDArray currentOut=output.getRow(i);
                //System.out.println(currentOut.toString());
                currentOutputString += currentResultImage(output.getRow(i)) + "";
            }

            evaluation.eval(next.getLabels(), output);
        }
        obtainStringResult(currentOutputString);
    }

    private int currentResultImage(INDArray outPut){
        int result=0;
        float currentMax=outPut.getFloat(0);

        for (int j = 1; j < outPut.length(); j++) {
            if (outPut.getFloat(j) > currentMax) {
                result = j;
                currentMax=outPut.getFloat(j);
            }
        }

        return result;
    }


    private void obtainStringResult(String ouput) throws IOException{
        PrintWriter writer = new PrintWriter("outPutMnist.txt", "UTF-8");

        writer.println(ouput);
        writer.close();
    }

    /**
     * Return the current neural network
     * @return
     */
    public MultiLayerNetwork getNetwork() {
        return network;
    }


}
