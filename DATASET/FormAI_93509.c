//FormAI DATASET v1.0 Category: Sudoku solver ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

void printSolution(int grid[N][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}

bool findUnassignedLocation(int grid[N][N], int *row, int *col){
	for (*row = 0; *row < N; (*row)++){
		for (*col = 0; *col < N; (*col)++){
			if (grid[*row][*col] == 0){
				return true;
			}
		}
	}
	return false;
}

bool usedInRow(int grid[N][N], int row, int num){
	for (int col = 0; col < N; col++){
		if (grid[row][col] == num){
			return true;
		}
	}
	return false;
}

bool usedInColumn(int grid[N][N], int col, int num){
	for (int row = 0; row < N; row++){
		if (grid[row][col] == num){
			return true;
		}
	}
	return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			if (grid[row + boxStartRow][col + boxStartCol] == num){
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return !usedInRow(grid, row, num)
		   && !usedInColumn(grid, col, num)
		   && !usedInBox(grid, row - row % 3, col - col % 3, num)
		   && grid[row][col] == 0;
}

bool solveSudoku(int grid[N][N]){
	int row, col;
	if (!findUnassignedLocation(grid, &row, &col)){
		return true;
	}
	for (int num = 1; num <= 9; num++){
		if (isSafe(grid, row, col, num)){
			grid[row][col] = num;
			if (solveSudoku(grid)){
				return true;
			}
			grid[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					   { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
					   { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
					   { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
					   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (solveSudoku(grid)){
		printSolution(grid);
	}
	else{
		printf("No solution exists\n");
	}
	return 0;
}