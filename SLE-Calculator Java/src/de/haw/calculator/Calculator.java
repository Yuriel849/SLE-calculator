package de.haw.calculator;

import de.haw.common.Matrix;
import de.haw.common.Solveable;
import de.haw.gaussjordan.GaussJordanElimination;

/**
 *
 */
public class Calculator 
{
	public static void main(String[] args)
	{
		InputReader input = new InputReader();
		Matrix system = input.getSystem();
		Solveable solver = new GaussJordanElimination(system);
		solver.solveSystem();
		System.out.println("Terminated");
	}
}