//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {
	// Initialize the game board
	int board[ROWS][COLUMNS];
	for(int row=0; row<ROWS; row++) {
		for(int col=0; col<COLUMNS; col++) {
			board[row][col] = 0;
		}
	}

	// Declare and initialize the bingo caller
	int caller[25];
	for(int i=0; i<25; i++) {
		caller[i] = i+1;
	}
	srand(time(NULL));

	// Play the game!
	int number;
	int rowSum, colSum, diagSum;
	int gameOver = 0;
	while(!gameOver) {
		// Call a new number
		int index = rand() % 25;
		number = caller[index];
		caller[index] = caller[24];
		caller[24] = number;
		
		// Mark the number on the board
		for(int row=0; row<ROWS; row++) {
			for(int col=0; col<COLUMNS; col++) {
				if(board[row][col] == number) {
					board[row][col] = -1;
				}
			}
		}
		
		// Check for a bingo
		for(int row=0; row<ROWS; row++) {
			rowSum = 0;
			colSum = 0;
			for(int col=0; col<COLUMNS; col++) {
				rowSum += board[row][col];
				colSum += board[col][row];
			}
			if(rowSum == -5 || colSum == -5) {
				printf("BINGO! Row %d or column %d\n", row+1, row+1);
				gameOver = 1;
				break;
			}
		}
		diagSum = board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4];
		if(diagSum == -5) {
			printf("BINGO! Diagonal from top left to bottom right\n");
			gameOver = 1;
		}
		diagSum = board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0];
		if(diagSum == -5) {
			printf("BINGO! Diagonal from top right to bottom left\n");
			gameOver = 1;
		}
	}

	return 0;
}