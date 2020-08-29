/**
 * 
 */
package de.haw.gaussjordan;

import de.haw.common.Matrix;
import de.haw.common.Solveable;

/**
 * @author test
 *
 */
public class GaussJordanElimination implements Solveable
{
	private Matrix sle;
	private static int i = 0;
	public GaussJordanElimination(Matrix system)
	{
		sle = system;
	}
	
	
	public void solveSystem()
	{
		System.out.println(i);
		if(i >= sle.getSize()) {
			sle.print();
		}
		else if(sle.getValue(i, i) == 0) {
			sle.swapRows(i, (i + 1));
			i++;
			GaussJordanElimination gse = new GaussJordanElimination(sle);
			gse.solveSystem();
		}
		else if(sle.getValue(i, i) == 1) {
			rowReduction(i);
			i++;
			GaussJordanElimination gse = new GaussJordanElimination(sle);
			gse.solveSystem();
		}
		else {
			scaleRow(i);
			rowReduction(i);
			i++;
			GaussJordanElimination gse = new GaussJordanElimination(sle);
			gse.solveSystem();
		}

	}


	private void scaleRow(int row) 
	{

		double mult  = (double)1 /sle.getValue(row, row);
		for(int j = 0; j <= sle.getSize(); j++) {
			double product = sle.getValue(row, j) * mult;
			sle.setValue(row, j, product);
		}
		
	}


	private void rowReduction(int currentRow) 
	{
		// TODO Auto-generated method stub
		
		for(int j = 0; j < sle.getSize(); j++) {
			if(j == currentRow) {
				--j;
				j++;
			}
			else {
				double mult = sle.getValue(j, currentRow);
						
				for(int k = 0; k <= sle.getSize(); k++) {
					sle.setValue(j, k, (sle.getValue(j, k) - (sle.getValue(currentRow, k)* mult)));
				}
			}
		}
		
	}
	
	
}
