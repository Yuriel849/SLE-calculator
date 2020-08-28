/**
 * 
 */
package de.haw.common;

import java.util.ArrayList;
import java.util.Collections;

public class Matrix 
{
	private ArrayList<ArrayList<Double>> rows;
	private int rowSize;
	
	public Matrix(int rowSize) 
	{
		this.rowSize = rowSize;
		rows = new ArrayList<>();
		
		for(int i = 0; i < rowSize; i++) {
			rows.add(new ArrayList<>(rowSize+1));
		}
	}
	
	public boolean setValue(int row, int column, double value) 
	{
		boolean result = false;
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize)
			rows.get(row).set(column, value);
		else
			System.out.println("Error: Row or column number is invalid.");
		
		return result;		
	}
	
	public double getValue(int row, int column) 
	{
		double result = -9999;
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize)
			result = rows.get(row).get(column);
		else
			System.out.println("Error: Row or column number is invalid.");
		
		return result;
	}
	
	public boolean setSize(int size)
	{
		boolean result = false;
		
		if(rowSize > size) {
			for(int i = rowSize; i > size; i--) {
				rows.remove(i - 1);
			}
			rowSize = size;
			result = true;
		}
		else if (rowSize < size) {
			for(int i = rowSize; i < size; i++) {
				rows.add(new ArrayList<>(size+1));
			}
			rowSize = size;
			result = true;
		}
		
		return result;
	}
	
	public int getSize()
	{
		return rowSize;
	}
	/**
	 * Prints matrix on the console
	 */
	public void print() 
	{
		// TODO Auto-generated method stub
		
	}
	/**
	 * Switches 2 rows of the matrix
	 * @param integer representing position of row to swap  
	 * @param integer representing position of row to swap
	 */
	public void switchRows(int rowA, int rowB) 
	{
		// TODO Auto-generated method stub
		Collections.swap(rows, rowA, rowB);
	}
	/**
	 * Multiplies a row with a coefficient
	 * @param row integer representing a row in a matrix 
	 * @param mult scaler for the row
	 */
	public void multRows(int row, double mult)
	{
		// TODO Auto-generated method stub
		
	}
	/**
	 * Subtract the current row form every other
	 * @param row integer representing the pivot row which will not be changed
	 */
	public void reduceRows(int row)
	{
		// TODO Auto-generated method stub
		
	}

}
