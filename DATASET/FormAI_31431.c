//FormAI DATASET v1.0 Category: Checkers Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the board size
#define SIZE 8

// Define the pieces
#define EMPTY '.'
#define WHITE 'W'
#define BLACK 'B'

// Define color codes for output
#define ANSI_WHITE "\x1b[37m"
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_RESET "\x1b[0m"

// Define the board and the turn
char board[SIZE][SIZE];
char turn;

// Function to initialize the board
void init_board() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i % 2 == j % 2) {
				if (i < 3)
					board[i][j] = BLACK;
				else if (i > 4)
					board[i][j] = WHITE;
				else
					board[i][j] = EMPTY;
			} else
				board[i][j] = EMPTY;
		}
	}
	turn = WHITE;
}

// Function to print the board
void print_board() {
	printf("    ");
	for (int i = 0; i < SIZE; i++) {
		printf("%c ", i + 'a');
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", i + 1);
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == WHITE) {
				printf(ANSI_WHITE "W " ANSI_RESET);
			} else if (board[i][j] == BLACK) {
				printf(ANSI_BLACK "B " ANSI_RESET);
			} else {
				if (i % 2 == j % 2)
					printf(ANSI_RED ". " ANSI_RESET);
				else
					printf(". ");
			}
		}
		printf("%d\n", i + 1);
	}
	printf("    ");
	for (int i = 0; i < SIZE; i++) {
		printf("%c ", i + 'a');
	}
	printf("\n");
}

// Function to check if a move is valid
bool is_valid_move(int row, int col, int nrow, int ncol) {
	if (nrow < 0 || nrow >= SIZE || ncol < 0 || ncol >= SIZE)
		return false;
	if (board[nrow][ncol] != EMPTY)
		return false;
	if (turn == WHITE) {
		if (nrow - row == 1 && abs(ncol - col) == 1)
			return true;
		else if (nrow - row == 2 && abs(ncol - col) == 2 && board[row + (nrow - row) / 2][col + (ncol - col) / 2] == BLACK)
			return true;
		else
			return false;
	} else {
		if (nrow - row == -1 && abs(ncol - col) == 1)
			return true;
		else if (nrow - row == -2 && abs(ncol - col) == 2 && board[row + (nrow - row) / 2][col + (ncol - col) / 2] == WHITE)
			return true;
		else
			return false;
	}
}

// Function to check if a piece can capture a piece
bool can_capture(int row, int col) {
	if (turn == WHITE) {
		if (row + 2 < SIZE && col + 2 < SIZE && board[row + 1][col + 1] == BLACK && board[row + 2][col + 2] == EMPTY)
			return true;
		if (row + 2 < SIZE && col - 2 >= 0 && board[row + 1][col - 1] == BLACK && board[row + 2][col - 2] == EMPTY)
			return true;
		if (row - 2 >= 0 && col + 2 < SIZE && board[row - 1][col + 1] == BLACK && board[row - 2][col + 2] == EMPTY)
			return true;
		if (row - 2 >= 0 && col - 2 >= 0 && board[row - 1][col - 1] == BLACK && board[row - 2][col - 2] == EMPTY)
			return true;
		return false;
	} else {
		if (row + 2 < SIZE && col + 2 < SIZE && board[row + 1][col + 1] == WHITE && board[row + 2][col + 2] == EMPTY)
			return true;
		if (row + 2 < SIZE && col - 2 >= 0 && board[row + 1][col - 1] == WHITE && board[row + 2][col - 2] == EMPTY)
			return true;
		if (row - 2 >= 0 && col + 2 < SIZE && board[row - 1][col + 1] == WHITE && board[row - 2][col + 2] == EMPTY)
			return true;
		if (row - 2 >= 0 && col - 2 >= 0 && board[row - 1][col - 1] == WHITE && board[row - 2][col - 2] == EMPTY)
			return true;
		return false;
	}
}

// Function to check if the game is over
bool is_game_over() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == WHITE && can_capture(i, j))
				return false;
			if (board[i][j] == BLACK && can_capture(i, j))
				return false;
			if (turn == WHITE && board[i][j] == WHITE && (is_valid_move(i, j, i+1, j+1) || is_valid_move(i, j, i+1, j-1)))
				return false;
			if (turn == BLACK && board[i][j] == BLACK && (is_valid_move(i, j, i-1, j+1) || is_valid_move(i, j, i-1, j-1)))
				return false;
		}
	}
	return true;
}

// Function to make a move
void make_move(int row, int col, int nrow, int ncol) {
	board[nrow][ncol] = board[row][col];
	board[row][col] = EMPTY;
	if (turn == WHITE && nrow == SIZE - 1) {
		board[nrow][ncol] = WHITE + 'K' - 'W';
	}
	if (turn == BLACK && nrow == 0) {
		board[nrow][ncol] = BLACK + 'K' - 'B';
	}
	if (abs(nrow - row) == 2 && abs(ncol - col) == 2) {
		board[row + (nrow - row) / 2][col + (ncol - col) / 2] = EMPTY;
		if (can_capture(nrow, ncol))
			return;
	}
	if (turn == WHITE)
		turn = BLACK;
	else
		turn = WHITE;
}

// Main function
int main() {
	init_board();
	while (!is_game_over()) {
		print_board();
		printf("%s's turn\n", turn == WHITE ? "White" : "Black");
		printf("Enter move (e.g. a3b4): ");
		char input[5];
		scanf("%s", input);
		int row = input[1] - '1';
		int col = input[0] - 'a';
		int nrow = input[3] - '1';
		int ncol = input[2] - 'a';
		if (is_valid_move(row, col, nrow, ncol)) {
			make_move(row, col, nrow, ncol);
		} else {
			printf("Invalid move!\n");
		}
	}
	print_board();
	printf("Game over!\n");
	if (turn == WHITE)
		printf("Black wins!\n");
	else
		printf("White wins!\n");
	return 0;
}