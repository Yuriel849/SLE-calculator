package de.haw.calculator;

import java.util.Scanner;
import de.haw.common.*;

/**
 * A class to handle user input of the number and values of the system of linear equations.
 * @author Mario
 *
 */
public class InputReader
{
	private Scanner scan;

	public InputReader()
	{
		scan = new Scanner(System.in);
	}

	/**
	 * Saves a system of linear equations in a Matrix instance.
	 * The user enters the number of equations and the coefficients and solutions of each equation.
	 * 
	 * @return A matrix containing the system of linear equations entered by the user.
	 */
	public Matrix getSystem()
	{
		boolean jnz = false;
		Integer rows = 0;
		String str = new String();
		Matrix mat;
		boolean entered = false;
		int i = 0;
		int j = 0;
		// Retrieves number of rows from the user input
		while (!jnz) {
			System.out.println("Enter number of equations > ");
			str = scan.nextLine().trim();
			rows = Integer.parseInt(str);
			if (rows > 1) {
				jnz = true;
			}
			else {
				System.out.println("Must be positive integer greater than 1");
			}
		}
		mat = new Matrix((int) rows);
		// Retrieves values of equation coefficients
		while (!entered) {
			System.out.println(
					"Enter the coeficients of the equation on a single line separated by space and press enter");
			System.out.print("> ");
			str = scan.nextLine().trim();
			String[] tokens = str.split(" ");
			boolean sEntered = false;
			if (tokens.length != (rows + 1)) {
				System.out.println("Try again:");
			}
			else {
				for (String s : tokens) {
					j %= (rows + 1);
					try {
						//@SuppressWarnings("unused")
						Double.parseDouble(s);
						sEntered = true;
					}
					catch (Exception e) {
						System.out.println("Not a number!");
						sEntered = false;
						break;
					}
					mat.setValue(i, j, Double.parseDouble(s));
					j++;
				}
				if (sEntered) {
					i++;
				}
				if (i == rows) {
					entered = true;
				}
			}
		}
		return mat;
	}
}