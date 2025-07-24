//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>

#define EMPTY 0
#define PLAYER 1
#define COMPUTER 2

#define PLAYERMOVE 1
#define COMPUTERMOVE 2

int board[3][3];
int turn = PLAYER;
int winner = EMPTY;

void printBoard() {
	printf("\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

int getWinner() {
	// Check rows for a winner
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if (board[i][0] == PLAYER) {
				return PLAYER;
			} else if (board[i][0] == COMPUTER) {
				return COMPUTER;
			}
		}
	}

	// Check columns for a winner
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			if (board[0][i] == PLAYER) {
				return PLAYER;
			} else if (board[0][i] == COMPUTER) {
				return COMPUTER;
			}
		}
	}

	// Check diagonals for a winner
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == PLAYER) {
			return PLAYER;
		} else if (board[0][0] == COMPUTER) {
			return COMPUTER;
		}
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == PLAYER) {
			return PLAYER;
		} else if (board[0][2] == COMPUTER) {
			return COMPUTER;
		}
	}

	// Check for a tie
	int emptyCount = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				emptyCount++;
			}
		}
	}

	if (emptyCount == 0) {
		return -1; // Tie
	}

	return EMPTY; // No winner yet
}

int getScore(int depth) {
	int score = 0;

	// Calculate score based on winner at current depth
	if (winner == PLAYER) {
		score = 10 - depth;
	} else if (winner == COMPUTER) {
		score = depth - 10;
	}

	return score;
}

int minimax(int depth, int move) {
	if (depth == 9 || winner != EMPTY) {
		return getScore(depth);
	}

	int bestScore;
	if (move == PLAYERMOVE) {
		bestScore = -100;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == EMPTY) {
					board[i][j] = PLAYER;
					turn = COMPUTER;
					winner = getWinner();
					int score = minimax(depth + 1, COMPUTERMOVE);
					bestScore = score > bestScore ? score : bestScore;
					board[i][j] = EMPTY;
					turn = PLAYER;
					winner = getWinner();
				}
			}
		}
	} else {
		bestScore = 100;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == EMPTY) {
					board[i][j] = COMPUTER;
					turn = PLAYER;
					winner = getWinner();
					int score = minimax(depth + 1, PLAYERMOVE);
					bestScore = score < bestScore ? score : bestScore;
					board[i][j] = EMPTY;
					turn = COMPUTER;
					winner = getWinner();
				}
			}
		}
	}

	return bestScore;
}

void computerMove() {
	int bestScore = -100;
	int bestI = -1;
	int bestJ = -1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY) {
				board[i][j] = COMPUTER;
				turn = PLAYER;
				winner = getWinner();
				int score = minimax(0, PLAYERMOVE);
				board[i][j] = EMPTY;
				turn = COMPUTER;
				winner = getWinner();
				if (score > bestScore) {
					bestScore = score;
					bestI = i;
					bestJ = j;
				}
			}
		}
	}

	board[bestI][bestJ] = COMPUTER;
	turn = PLAYER;
}

void playerMove() {
	int i, j;
	printf("Enter row: ");
	scanf("%d", &i);
	printf("Enter column: ");
	scanf("%d", &j);

	if (board[i - 1][j - 1] == EMPTY) {
		board[i - 1][j - 1] = PLAYER;
		turn = COMPUTER;
	} else {
		printf("Invalid move, try again.\n");
		playerMove();
	}
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = EMPTY;
		}
	}

	printBoard();

	while (winner == EMPTY) {
		if (turn == PLAYER) {
			playerMove();
		} else {
			computerMove();
		}

		printBoard();
		winner = getWinner();
	}

	if (winner == PLAYER) {
		printf("You win!");
	} else if (winner == COMPUTER) {
		printf("Computer wins!");
	} else {
		printf("Tie game.");
	}

	return 0;
}