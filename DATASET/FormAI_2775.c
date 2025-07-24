//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Define size of the board
#define MAX_NUM 8 // Define maximum number that can appear on the board

void print_board(int board[][BOARD_SIZE], int visible[][BOARD_SIZE]) {
    printf("   ");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for (int j=0; j<BOARD_SIZE; j++) {
            if (visible[i][j]) { // If the tile is visible
                printf("%d|", board[i][j]);
            }
            else {
                printf(" |");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize all elements to 0
    int visible[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize all elements to 0
    int num_pairs = (BOARD_SIZE * BOARD_SIZE) / 2; // Calculate number of pairs
    int nums[MAX_NUM] = {0}; // Array to store the numbers that will be paired
    for (int i=0; i<num_pairs; i++) {
        int num = rand() % MAX_NUM + 1; // Generate random number between 1 and MAX_NUM
        while (nums[num-1] == 2) { // If the number has already been paired twice, generate a new number
            num = rand() % MAX_NUM + 1;
        }
        nums[num-1]++; // Increment the count of the number
        int found = 0;
        while (!found) {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            if (board[row][col] == 0) { // If the tile is empty
                board[row][col] = num;
                found = 1;
            }
        }
        found = 0;
        while (!found) {
            int row = rand() % BOARD_SIZE;
            int col = rand() % BOARD_SIZE;
            if (board[row][col] == 0) { // If the tile is empty
                board[row][col] = num;
                found = 1;
            }
        }
    }

    int num_guesses = 0;
    while (1) { // Run infinite loop until user exits
        print_board(board, visible);
        printf("Enter row and column to reveal a tile (e.g. 1 2): ");
        int row, col;
        scanf("%d %d", &row, &col); // Get user input
        row--;
        col--;
        if (visible[row][col]) { // If the tile has already been revealed
            printf("Tile already revealed\n");
        }
        else { // If the tile has not been revealed
            visible[row][col] = 1;
            num_guesses++;
            if (num_guesses % 2 == 0) { // If two tiles have been revealed
                int r1, c1, r2, c2;
                for (int i=0; i<BOARD_SIZE; i++) {
                    for (int j=0; j<BOARD_SIZE; j++) {
                        if (visible[i][j] == 1 && r1 == -1) {
                            r1 = i;
                            c1 = j;
                        }
                        else if (visible[i][j] == 1) {
                            r2 = i;
                            c2 = j;
                            break;
                        }
                    }
                }
                if (board[r1][c1] == board[r2][c2]) { // If the two tiles form a pair
                    printf("You found a pair!\n");
                }
                else { // If the two tiles do not form a pair
                    printf("Try again\n");
                    visible[r1][c1] = 0;
                    visible[r2][c2] = 0;
                }
            }
            int found_all = 1;
            for (int i=0; i<BOARD_SIZE; i++) {
                for (int j=0; j<BOARD_SIZE; j++) {
                    if (visible[i][j] == 0) { // If there is still an unpaired tile
                        found_all = 0;
                        break;
                    }
                }
            }
            if (found_all) { // If all tiles have been paired
                printf("Congratulations! You win!\n");
                break; // Exit the loop to end the game
            }
        }
    }

    return 0;
}