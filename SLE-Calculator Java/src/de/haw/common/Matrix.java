/**
 * 
 */
package de.haw.common;

import java.util.ArrayList;
import java.util.Collections;

public class Matrix 
{
	final private ArrayList<ArrayList<Double>> rows;
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
		ArrayList<Double> targetRow = rows.get(row);
		int targetSize = targetRow.size();
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize) {
			if(targetSize > column)
				targetRow.set(column, value);
			else {
				for(int i = targetSize; i <= rowSize; i++) {
					if(i != column)
						targetRow.add(0.0);
				}
				targetRow.add(value);
			}
		} else
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
		for(int i = 0; i < rowSize; i++) {
			System.out.println(rows.get(i));
			
		}		
	}
}