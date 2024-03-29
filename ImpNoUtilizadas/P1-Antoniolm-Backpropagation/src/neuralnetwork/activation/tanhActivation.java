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

/**
 *
 * @author LENOVO
 */
public class tanhActivation implements Activation{

    @Override
    public double evaluate(double value) {
        double e2z= Math.exp(2*value);
        return (e2z-1)/(e2z+1);
    }

    @Override
    public double diff(double value) {
        double result=evaluate(value);
        return 1-result*result;
    }
    
}
