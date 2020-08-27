package de.haw.common;

import java.util.ArrayList;

public class Matrix {
	public ArrayList<ArrayList<Double>> rows;
	int rowSize;
	
	public Matrix(int rowSize) {
		this.rowSize = rowSize;
		rows = new ArrayList<>();
		
		for(int i = 0; i < rowSize; i++) {
			rows.add(new ArrayList<>());
		}
	}
}
