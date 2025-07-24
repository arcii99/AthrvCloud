//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_SHIPS 3

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int ship_locations[NUM_SHIPS][2];
    int num_ships_sunk = 0;
    int num_guesses = 0;
    
    // Initialize board with water
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '~';
        }
    }
    
    // Randomly place ships on board
    srand(time(NULL));
    for (int i = 0; i < NUM_SHIPS; i++) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        ship_locations[i][0] = row;
        ship_locations[i][1] = col;
        board[row][col] = 'S';
    }
    
    // Game loop
    while (num_ships_sunk < NUM_SHIPS) {
        // Print board
        printf("\nGuesses: %d\n", num_guesses);
        printf("  ");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
        }
        printf("\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        
        // Get user guess
        int guess_row, guess_col;
        printf("\nEnter your guess:\n");
        scanf("%d %d", &guess_row, &guess_col);
        
        // Check if guess hits a ship or misses
        if (board[guess_row][guess_col] == 'S') {
            board[guess_row][guess_col] = 'H';
            printf("Hit!\n");
            num_guesses++;
            for (int i = 0; i < NUM_SHIPS; i++) {
                if (guess_row == ship_locations[i][0] && guess_col == ship_locations[i][1]) {
                    ship_locations[i][0] = -1;
                    ship_locations[i][1] = -1;
                    num_ships_sunk++;
                }
            }
        } else if (board[guess_row][guess_col] == '~') {
            board[guess_row][guess_col] = 'M';
            printf("Miss!\n");
            num_guesses++;
        } else {
            printf("You already guessed that!\n");
        }
    }
    
    printf("\nCongratulations, you sank all the ships with %d guesses!\n", num_guesses);
    
    return 0;
}