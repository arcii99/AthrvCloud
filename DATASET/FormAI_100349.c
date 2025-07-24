//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

// Global Variables
int board[BOARD_SIZE][BOARD_SIZE] = {0};
int ships[5] = {5, 4, 3, 3, 2};
int num_sunk = 0;

// Function to Print Board
void print_board() {
    printf("   ");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("- ");
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c| ", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to Place Ships
void place_ships() {
    for (int i = 0; i < 5; i++) {
        // Randomly Select Starting Point
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        // Randomly Select Orientation
        int orientation = rand() % 2; // 0 - Horizontal, 1 - Vertical

        // Check If Ship Fits
        int fits = 1;
        for (int j = 0; j < ships[i]; j++) {
            int new_row = row + (orientation == 1 ? j : 0);
            int new_col = col + (orientation == 0 ? j : 0);
            if (new_row >= BOARD_SIZE || new_col >= BOARD_SIZE || board[new_row][new_col] != 0) {
                fits = 0;
                break;
            }
        }

        // Place Ship
        if (fits) {
            for (int j = 0; j < ships[i]; j++) {
                int new_row = row + (orientation == 1 ? j : 0);
                int new_col = col + (orientation == 0 ? j : 0);
                board[new_row][new_col] = ships[i];
            }
        }
        else {
            i--;
        }
    }

    printf("Ships Placed!\n");
}

// Function to Take a Guess
void take_guess() {
    int row, col;
    printf("Enter Guess (e.g. A5): ");
    scanf(" %c%d", &row, &col);
    row -= 'A';

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] == -1) {
        printf("Invalid Guess.\n");
    }
    else {
        if (board[row][col] == 0) {
            printf("Miss!\n");
            board[row][col] = -1;
        }
        else {
            printf("Hit!\n");
            board[row][col] = -1;
            ships[board[row][col] - 2]--;
            if (ships[board[row][col] - 2] == 0) {
                printf("Ship Sunk!\n");
                num_sunk++;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed Random Number Generator
    place_ships();
    print_board();

    while (num_sunk < 5) {
        take_guess();
        print_board();
    }

    printf("You Win!\n");

    return 0;
}