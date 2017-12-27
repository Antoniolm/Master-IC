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

package neuralnetwork.activation;

import neuralnetwork.activation.Activation;
import static java.lang.Math.exp;

/**
 *
 * @author LENOVO
 */
public class SigmoidActivation implements Activation{

    @Override
    public double evaluate(double value) {
        return 1.0/(1.0+Math.exp(value));
    }

    @Override
    public double diff(double value) {
        double result=evaluate(value);
        return result*(1-result);
    }
    
}
