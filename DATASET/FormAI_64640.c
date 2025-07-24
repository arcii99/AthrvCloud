//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: medieval
#include<stdio.h>

// Function to display the board in medieval style
void displayBoard(char board[][3]) {

	printf("\n");
	printf("       |       |      \n");
	printf("   %c   |   %c   |   %c   \n", board[0][0], board[0][1], board[0][2]);
	printf("       |       |      \n");
	printf("-------+-------+-------\n");
	printf("       |       |      \n");
	printf("   %c   |   %c   |   %c   \n", board[1][0], board[1][1], board[1][2]);
	printf("       |       |      \n");
	printf("-------+-------+-------\n");
	printf("       |       |      \n");
	printf("   %c   |   %c   |   %c   \n", board[2][0], board[2][1], board[2][2]);
	printf("       |       |      \n");
}

// Function to check if the player has won the game
int checkWin(char board[][3], char token) {

	// Checking the rows for a win
	if ((board[0][0] == token && board[0][1] == token && board[0][2] == token) ||
		(board[1][0] == token && board[1][1] == token && board[1][2] == token) ||
		(board[2][0] == token && board[2][1] == token && board[2][2] == token)) {
		return 1;
	}

	// Checking the columns for a win
	if ((board[0][0] == token && board[1][0] == token && board[2][0] == token) ||
		(board[0][1] == token && board[1][1] == token && board[2][1] == token) ||
		(board[0][2] == token && board[1][2] == token && board[2][2] == token)) {
		return 1;
	}

	// Checking the diagonals for a win
	if ((board[0][0] == token && board[1][1] == token && board[2][2] == token) ||
		(board[0][2] == token && board[1][1] == token && board[2][0] == token)) {
		return 1;
	}

	return 0;
}

// Main Function that controls the flow of the game
int main() {

	char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	char player = 'X';
	int row, col;
	int counter = 0;

	printf("Welcome to Medieval Tic Tac Toe\n");
	displayBoard(board);

	while (counter < 9) {

		if (player == 'X') {
			printf("Player 1's Turn: Enter Row and Column\n");
			scanf("%d %d", &row, &col);
			board[row - 1][col - 1] = player;
			displayBoard(board);

			if (checkWin(board, player)) {
				printf("Player 1 Wins the game!\n");
				return 0;
			}
			player = 'O';
			counter++;
		}
		else {
			printf("Player 2's Turn: Enter Row and Column\n");
			scanf("%d %d", &row, &col);
			board[row - 1][col - 1] = player;
			displayBoard(board);

			if (checkWin(board, player)) {
				printf("Player 2 Wins the game!\n");
				return 0;
			}

			player = 'X';
			counter++;
		}
	}

	printf("Game ends in a Draw\n");
	return 0;
}