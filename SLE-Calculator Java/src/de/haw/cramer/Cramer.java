package de.haw.cramer;

import de.haw.common.Matrix;
import de.haw.common.Solveable;

/**
 * Solves a system of linear equations using Cramer's Rule.
 * 
 * @author Yuriel
 * @version 08.09.2020.
 */
public class Cramer implements Solveable {
	private Matrix system;
	
	public Cramer(Matrix system) {
		this.system = system;
	}
	
	@Override
	public void solveSystem() {
		// Find the determinant for "system".
		double systemDeterminant = calculateDeterminant(system);
		
		// TODO Find the determinant for each matrix, where one column of "system" is replaced with the solutions vector.
		
		// TODO Calculate the variable values by determining each value as det / det.
		
	}

	/**
	 * Calculates the determinant of the nxm matrix passed as an argument.
	 * The rightmost column, which represents the solutions vector, is ignored.
	 *  
	 * @param matrix The matrix for which the determinant is to be calculated.
	 * @return The determinant.
	 */
	public double calculateDeterminant(Matrix matrix) {
		double determinant = 0;
		
		return determinant;
	}
}
