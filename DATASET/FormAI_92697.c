//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 10
#define ALIEN_ROW 2
#define ALIEN_COL 4
#define PLAYER_ROW 5

// Function prototypes
void initialize_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
void move_player(char board[ROWS][COLS], int move);
void move_aliens(char board[ROWS][COLS]);
void shoot(char board[ROWS][COLS]);
int get_random_int(int min, int max);

int main() {
	// Seed the random number generator
	srand(time(NULL));

	// Initialize variables
	char board[ROWS][COLS];
	int move;

	// Initialize board and print it out
	initialize_board(board);
	print_board(board);

	// Game loop
	while (1) {
		// Get input from player
		printf("Move left (-1), right (1), or stay put (0): ");
		scanf("%d", &move);

		// Move the player
		move_player(board, move);

		// Move the aliens
		move_aliens(board);

		// Fire a shot
		shoot(board);

		// Print out the board
		print_board(board);
	}

	return 0;
}

void initialize_board(char board[ROWS][COLS]) {
	// Initialize all elements to ' '
	for (int row=0; row<ROWS; row++) {
		for (int col=0; col<COLS; col++) {
			board[row][col] = ' ';
		}
	}

	// Place the aliens
	for (int row=0; row<ALIEN_ROW; row++) {
		for (int col=0; col<COLS; col++) {
			board[row][col] = 'A';
		}
	}
	
	// Place the player
	board[PLAYER_ROW][ALIEN_COL] = 'P';
}

void print_board(char board[ROWS][COLS]) {
	// Print top boundary
	printf("+");
	for (int col=0; col<COLS; col++) {
		printf("-");
	}
	printf("+\n");

	// Print rows
	for (int row=0; row<ROWS; row++) {
		printf("|");
		for (int col=0; col<COLS; col++) {
			printf("%c", board[row][col]);
		}
		printf("|\n");
	}

	// Print bottom boundary
	printf("+");
	for (int col=0; col<COLS; col++) {
		printf("-");
	}
	printf("+\n");
}

void move_player(char board[ROWS][COLS], int move) {
	// Get current position of player
	int player_col;
	for (int col=0; col<COLS; col++) {
		if (board[PLAYER_ROW][col] == 'P') {
			player_col = col;
			break;
		}
	}

	// Determine new position of player
	int new_col = player_col + move;
	if (new_col < 0) {
		new_col = 0;
	}
	else if (new_col >= COLS) {
		new_col = COLS - 1;
	}

	// Move the player
	board[PLAYER_ROW][player_col] = ' ';
	board[PLAYER_ROW][new_col] = 'P';
}

void move_aliens(char board[ROWS][COLS]) {
	// Move aliens down one row
	for (int row=ROWS-1; row>=1; row--) {
		for (int col=0; col<COLS; col++) {
			board[row][col] = board[row-1][col];
		}
	}

	// Randomly move aliens left or right in last row
	int direction = get_random_int(-1, 1);
	if (board[0][0] == 'A' && direction == -1) {
		direction = 1;
	}
	else if (board[0][COLS-1] == 'A' && direction == 1) {
		direction = -1;
	}
	for (int col=0; col<COLS; col++) {
		board[0][col] = ' ';
	}
	for (int col=0; col<COLS; col++) {
		if (board[0][col-direction] == 'A') {
			board[0][col] = 'A';
		}
	}
}

void shoot(char board[ROWS][COLS]) {
	// Determine if a shot is fired
	if (get_random_int(1, 10) <= 5) {
		return;
	}

	// Find the position of the player
	int player_col;
	for (int col=0; col<COLS; col++) {
		if (board[PLAYER_ROW][col] == 'P') {
			player_col = col;
			break;
		}
	}

	// Starting from the row below the player, search for the first alien
	for (int row=PLAYER_ROW+1; row<ROWS; row++) {
		if (board[row][player_col] == 'A') {
			board[row][player_col] = ' ';
			break;
		}
	}
}

int get_random_int(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}