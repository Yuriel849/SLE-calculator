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
			rows.add(new ArrayList<>());
			for(int j = 0; j <= rowSize; j++) {
				rows.get(i).add(0.0);
			}
		}
	}
	
	public boolean setValue(int row, int column, double value) 
	{
		boolean result = false;
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize) {
			rows.get(row).set(column, value);
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

	public void setRow(int index, ArrayList<Double> newRow) {
		rows.set(index, newRow);
	}
	
	public ArrayList<Double> getRow(int index) {
		ArrayList<Double> result = null;
		
		if(0 <= index && index < rowSize)
			result = rows.get(index);
		
		return result;
	}
	
	public void swapRows(int rowA, int rowB) {
		Collections.swap(rows, rowA, rowB);
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