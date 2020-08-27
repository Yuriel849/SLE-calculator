/**
 * 
 */
package de.haw.calculator;

import de.haw.common.Matrix;
import de.haw.common.Solveable;
import de.haw.gaussjordan.GaussJordanElimination;

/**
 * @author test
 *
 */
public class Calculator {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Matrix system = InputReader.getSystem();
		Solveable solver = new GaussJordanElimination();
		solver.solveSystem(system);

	}

}
