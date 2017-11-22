package PracticaIC.NeuralNetwork;

import org.deeplearning4j.nn.multilayer.MultiLayerNetwork;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;

/**
 * Created by LENOVO on 08/11/2017.
 */
public abstract class NeuralNetwork {
    protected MultiLayerNetwork network;

    public abstract void train();
    public abstract void eval();
    public MultiLayerNetwork getNetwork() {
        return network;
    }


}
