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
import org.nd4j.linalg.lossfunctions.LossFunctions;

/**
 * Created by LENOVO on 08/11/2017.
 */
public class NNSingleLayer extends NeuralNetwork {

    public NNSingleLayer(int rngSeed,int numRows, int numColumns,int outputNum){
        MultiLayerConfiguration conf = new NeuralNetConfiguration.Builder()
            .seed(rngSeed)
            .optimizationAlgo(OptimizationAlgorithm.STOCHASTIC_GRADIENT_DESCENT)
            .iterations(1)
            .learningRate(0.06) //specify the learning rate
            .updater(Updater.NESTEROVS)
            .regularization(true).l2(1e-4)
            .list()
            .layer(0, new DenseLayer.Builder() //create the first, input layer with xavier initialization
                .nIn(numRows * numColumns)
                .nOut(10)
                .activation(Activation.SIGMOID)
                .weightInit(WeightInit.RELU)
                .build())
            .layer(1, new OutputLayer.Builder(LossFunctions.LossFunction.NEGATIVELOGLIKELIHOOD) //create hidden layer
                .nIn(10)
                .nOut(outputNum)
                .activation(Activation.SOFTMAX)
                .weightInit(WeightInit.RELU)
                .build())
            .pretrain(false).backprop(true) //use backpropagation to adjust weights
            .build();

        network = new MultiLayerNetwork(conf);
        network.init();
        //print the score with every 1 iteration
        network.setListeners(new ScoreIterationListener(1));
    }

    public void train() {

    }

    public void eval() {

    }
}
