//FormAI DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {{0}};
    int numPairs = BOARD_SIZE * BOARD_SIZE / 2;
    int pairsFound = 0;
    
    // Set up the board
    for (int i = 0; i < numPairs; i++) {
        // Randomly choose two coordinates for the pair
        int row1 = rand() % BOARD_SIZE;
        int col1 = rand() % BOARD_SIZE;
        int row2, col2;
        do {
            row2 = rand() % BOARD_SIZE;
            col2 = rand() % BOARD_SIZE;
        } while (row2 == row1 && col2 == col1);
        
        // Assign the same number to both coordinates
        board[row1][col1] = i + 1;
        board[row2][col2] = i + 1;
    }
    
    // Shuffle the board
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        // Randomly choose two coordinates to swap
        int row1 = rand() % BOARD_SIZE;
        int col1 = rand() % BOARD_SIZE;
        int row2 = rand() % BOARD_SIZE;
        int col2 = rand() % BOARD_SIZE;
        
        // Swap the values at the two coordinates
        int temp = board[row1][col1];
        board[row1][col1] = board[row2][col2];
        board[row2][col2] = temp;
    }
    
    // Start the game
    while (pairsFound < numPairs) {
        system("clear"); // Clear the console
        printf("Pairs found: %d / %d\n\n", pairsFound, numPairs);
        printBoard(board);
        
        // Prompt the user to choose a coordinate
        int row, col;
        printf("\nEnter coordinates separated by a space: ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        
        // If the coordinate has already been revealed, do nothing
        if (revealed[row][col]) continue;
        
        // Reveal the coordinate
        revealed[row][col] = 1;
        printf("The value at (%d, %d) is %d\n", row + 1, col + 1, board[row][col]);
        
        // Check if the user has found a pair
        int foundPair = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (revealed[i][j]) {
                    if (board[i][j] == board[row][col] && (i != row || j != col)) {
                        pairsFound++;
                        foundPair = 1;
                    }
                }
            }
        }
        
        // If the user found a pair, print a message and wait for a key press
        if (foundPair) {
            printf("You found a pair!\nPress enter to continue...");
            getchar(); // Wait for a key press
            getchar(); // Prevent the enter key from immediately revealing the next coordinate
        }
    }
    
    // End of game
    printf("Congratulations, you found all the pairs!\n");
    printBoard(board);
    
    return 0;
}