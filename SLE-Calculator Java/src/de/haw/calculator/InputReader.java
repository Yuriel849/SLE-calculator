/**
 * 
 */
package de.haw.calculator;

import java.util.Scanner;
import de.haw.common.*;

/**
 * @author test
 *
 */
public class InputReader 
{
	private Scanner scan;
	
	public InputReader()
	{
		scan = new Scanner(System.in);
	}
	
	public Matrix getSystem()
	{
		boolean jnz =false;
		Integer rows = 0;
		String str = new String();
		Matrix mat;
		boolean entered = false;
		int i = 0;
		int j = 0;
			// Retrieves number of rows from the user input
	    	while(!jnz) {
	    		System.out.println("Enter number of equations > ");
	    		str = scan.nextLine().trim();
	    		rows = Integer.parseInt(str);
	    		if(rows > 1){
	    			jnz = true;
	    		}
	    		else {
	    			System.out.println("Must be positive integer greater than 1");
	    		}
	    	}
	    mat = new Matrix((int)rows);
	    	// Retrieves values of equation coefficients
	    	while(!entered) {
	    		System.out.println("Enter the coeficients of the equation on a single line separated by space and press enter");
	    		System.out.print("> ");
	    		str = scan.nextLine().trim();
	    		String[] tokens = str.split(" ");
	    		 if(tokens.length != (rows + 1)) {
	    		 	 System.out.println("Try again:");
	    		 }
	    		 else {
	    			 for(String s : tokens) {
	    				 j %=(rows + 1);
	    				 mat.setValue(i,j ,Double.parseDouble(s));
	    				 j++;
	    			 }
	    			 i++;
	    			 	if(i == rows) {
	    			 		entered = true;
	    			 	}
	    		 }
	    	}
		
		return mat;
	}

}
	
