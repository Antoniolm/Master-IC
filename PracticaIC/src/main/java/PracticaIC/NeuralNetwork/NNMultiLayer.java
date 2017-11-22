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
import org.nd4j.linalg.learning.config.Nesterovs;
import org.nd4j.linalg.lossfunctions.LossFunctions;

/**
 * Created by LENOVO on 08/11/2017.
 */
public class NNMultiLayer extends NeuralNetwork {
    public NNMultiLayer(int rngSeed,int numRows, int numColumns,int outputNum){
        MultiLayerConfiguration conf = new NeuralNetConfiguration.Builder()
            .seed(rngSeed) //include a random seed for reproducibility
            .optimizationAlgo(OptimizationAlgorithm.STOCHASTIC_GRADIENT_DESCENT) // use stochastic gradient descent as an optimization algorithm
            .iterations(1)
            .activation(Activation.RELU)
            .weightInit(WeightInit.XAVIER)
            .learningRate(0.06) //specify the learning rate
            .updater(new Nesterovs(0.98))
            .regularization(true).l2(0.06 * 0.005) // regularize learning model
            .list()
            .layer(0, new DenseLayer.Builder() //create the first input layer.
                .nIn(numRows * numColumns)
                .nOut(500)
                .build())
            .layer(1, new DenseLayer.Builder() //create the second input layer
                .nIn(500)
                .nOut(100)
                .build())
            .layer(2, new OutputLayer.Builder(LossFunctions.LossFunction.NEGATIVELOGLIKELIHOOD) //create hidden layer
                .activation(Activation.SOFTMAX)
                .nIn(100)
                .nOut(outputNum)
                .build())
            .pretrain(false).backprop(true) //use backpropagation to adjust weights
            .build();

        MultiLayerNetwork model = new MultiLayerNetwork(conf);
        model.init();
        model.setListeners(new ScoreIterationListener(5));  //print the score with every iteration
    }

    public void train() {

    }

    public void eval() {

    }
}
