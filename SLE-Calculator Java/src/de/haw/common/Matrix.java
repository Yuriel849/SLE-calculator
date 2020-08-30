/**
 * A mxn matrix represented as an ArrayList of ArrayLists, which double values for each element.
 * 
 * @author Yuriel
 * @version 2020.08.30
 */
package de.haw.common;

import java.util.ArrayList;
import java.util.Collections;

public class Matrix 
{
	final private ArrayList<ArrayList<Double>> rows;
	private int rowSize;
	
	/**
	 * Creates a mxn matrix of size (rowSize)x(rowSize+1),
	 * and initializes all elements as double values, "0.0".
	 * @param rowSize The desired number of rows (== linear equations).
	 */
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
	
	/**
	 * Sets a specific value at a specific location, the designated row and column.
	 * The value at the specified location is only changed if the row and column numbers are valid. 
	 * 
	 * @param row The target row.
	 * @param column The target column.
	 * @param value The new value to be set at the specified location.
	 * @return True if the value was changed, and False otherwise.
	 */
	public boolean setValue(int row, int column, double value) 
	{
		boolean result = false;
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize) {
			rows.get(row).set(column, value);
		} else
			System.out.println("Error: Row or column number is invalid.");
		
		return result;
	}

	/**
	 * Gets the value at the designated location, the intersection of the row and column.
	 * 
	 * @param row The target row.
	 * @param column The target column.
	 * @return The double value at the designated location.
	 */
	public double getValue(int row, int column) 
	{
		double result = -9999;
		
		if(0 <= row && row < rowSize && 0 <= column && column <= rowSize)
			result = rows.get(row).get(column);
		else
			System.out.println("Error: Row or column number is invalid.");
		
		return result;
	}
	
	/**
	 * Sets a new size for the matrix.
	 * If the new size is smaller than the current size, reduces the size of the matrix.
	 * If the new size is larger than the current size, increases the size of the matrix.
	 * Nothing happens if the new size is the same as the current size.
	 * @param size
	 * @return True if the matrix is changed and the size is increased or decreased,
	 * False if no change is made.
	 */
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

	/**
	 * Gets the size of the matrix, specifically the number of rows.
	 * 
	 * @return The number of rows in the matrix.
	 */
	public int getSize()
	{
		return rowSize;
	}

	/**
	 * Replace a row in the matrix with a new row.
	 * 
	 * @param index The index of the row to be replaced.
	 * @param newRow The new row to take the place of the old.
	 */
	public void setRow(int index, ArrayList<Double> newRow) {
		rows.set(index, newRow);
	}
	
	/**
	 * Returns the row of the matrix at the designated index.
	 * 
	 * @param index The index of the row to be returned.
	 * @return The designated row.
	 */
	public ArrayList<Double> getRow(int index) {
		ArrayList<Double> result = null;
		
		if(0 <= index && index < rowSize)
			result = rows.get(index);
		
		return result;
	}

	/**
	 * Swaps two rows in the matrix.
	 * 
	 * @param rowA The first row.
	 * @param rowB The second row.
	 */
	public void swapRows(int rowA, int rowB) {
		Collections.swap(rows, rowA, rowB);
	}
	
	/**
	 * Prints matrix to the console.
	 */
	public void print() 
	{
		for(int i = 0; i < rowSize; i++) {
			System.out.println(rows.get(i));	
		}
	}
}