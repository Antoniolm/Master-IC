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
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;
import org.nd4j.linalg.learning.config.Nesterovs;
import org.nd4j.linalg.lossfunctions.LossFunctions;

public class NNMultiLayer extends NeuralNetwork {
    public NNMultiLayer(int inputNum,int outputNum){
        input=inputNum;
        output=outputNum;

        MultiLayerConfiguration configuration = new NeuralNetConfiguration.Builder()
            .optimizationAlgo(OptimizationAlgorithm.STOCHASTIC_GRADIENT_DESCENT)
            .learningRate(0.05)
            .updater(Updater.NESTEROVS)
            .list()
            .layer(0, new DenseLayer.Builder()
                .nIn(inputNum)
                .nOut(250)
                .activation(Activation.TANH)
                .weightInit(WeightInit.UNIFORM)
                .build())
            .layer(1, new DenseLayer.Builder()
                .nIn(250)
                .nOut(250)
                .activation(Activation.TANH)
                .weightInit(WeightInit.UNIFORM)
                .build())
            .layer(2, new DenseLayer.Builder()
                    .nIn(250)
                    .nOut(250)
                    .activation(Activation.TANH)
                    .weightInit(WeightInit.UNIFORM)
                    .build())
            .layer(3, new OutputLayer.Builder()
                .nIn(250)
                .nOut(outputNum)
                .activation(Activation.SOFTMAX)
                .weightInit(WeightInit.UNIFORM)
                .build())
            .pretrain(false).backprop(true)
            .build();

        network = new MultiLayerNetwork(configuration);
        network.init();
        network.setListeners(new ScoreIterationListener(5));
    }

}
