//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 40
#define COLS 80

int current[ROWS][COLS];
int future[ROWS][COLS];

int main() {
	srand(time(NULL));

	// Initialize the current state with random values
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			current[i][j] = rand() % 2;
		}
	}

	// Run the game for 100 generations
	for (int k = 0; k < 100; k++) {
		// Print the current state to the console
		system("clear");
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				printf("%s", current[i][j] ? "X " : ". ");
			}
			printf("\n");
		}

		// Compute the future state
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				// Count the live neighbors
				int count = 0;
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						int row = (i + x + ROWS) % ROWS;
						int col = (j + y + COLS) % COLS;
						count += current[row][col];
					}
				}
				count -= current[i][j];

				// Apply the rules of the game
				if (current[i][j] == 1 && (count < 2 || count > 3)) {
					future[i][j] = 0;
				} else if (current[i][j] == 0 && count == 3) {
					future[i][j] = 1;
				} else {
					future[i][j] = current[i][j];
				}
			}
		}

		// Copy the future state to the current state
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				current[i][j] = future[i][j];
			}
		}

		// Delay for dramatic effect
		struct timespec delay = { 0, 50000000 };
		nanosleep(&delay, NULL);
	}

	return 0;
}