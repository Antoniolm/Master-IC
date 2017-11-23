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

import org.deeplearning4j.eval.Evaluation;
import org.deeplearning4j.nn.multilayer.MultiLayerNetwork;
import org.nd4j.linalg.dataset.api.iterator.DataSetIterator;

/**
 * Created by LENOVO on 08/11/2017.
 */
public abstract class NeuralNetwork {
    protected MultiLayerNetwork network;
    Evaluation evaluation;

    /**
     *
     * @param dataSetIt
     */
    public abstract void train(DataSetIterator dataSetIt);

    /**
     *
     */
    public void showResults(){
        System.out.println(evaluation.stats());
    }

    /**
     *
     */
    public abstract void eval();

    /**
     *
     * @return
     */
    public MultiLayerNetwork getNetwork() {
        return network;
    }


}
