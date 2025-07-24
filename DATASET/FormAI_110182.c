//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int i, j, row1, col1, row2, col2, num_pairs = 0;
    char choices[16] = {0};
    srand(time(NULL));

    // Fill board with random numbers
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            while(1) {
                int num = rand() % 8 + 1;
                int k;
                for(k=0; k<i*BOARD_SIZE+j; k++) {  // Check if the number already exists
                    if(choices[k] == num) {
                        break;
                    }
                }
                if(k == i*BOARD_SIZE+j) {  // If the number doesn't exist
                    board[i][j] = num;
                    choices[i*BOARD_SIZE+j] = num;
                    break;
                }
            }
        }
    }

    // Start Game
    while(num_pairs < BOARD_SIZE*BOARD_SIZE/2) {  // Continue until all pairs are found
        // Print Board
        for(i=0; i<BOARD_SIZE; i++) {
            for(j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] < 10) {
                    printf(" %d ", board[i][j]);
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }

        // Get 1st Card
        printf("Enter the row and column of the 1st card (e.g. 1 3): ");
        scanf("%d %d", &row1, &col1);
        board[row1-1][col1-1] |= 16;  // Flip the 5th bit to indicate the card is flipped

        // Get 2nd Card
        printf("Enter the row and column of the 2nd card (e.g. 2 4): ");
        scanf("%d %d", &row2, &col2);
        board[row2-1][col2-1] |= 16;  // Flip the 5th bit to indicate the card is flipped

        // Check if matched
        if(board[row1-1][col1-1] == board[row2-1][col2-1] && (row1-1 != row2-1 || col1-1 != col2-1)) {  // If the 2 cards match
            board[row1-1][col1-1] |= 32;  // Flip the 6th bit to indicate the card is matched
            board[row2-1][col2-1] |= 32;  // Flip the 6th bit to indicate the card is matched
            num_pairs++;
        } else {  // If the 2 cards don't match
            board[row1-1][col1-1] &= 15;  // Flip the 5th bit back to indicate the card is unflipped
            board[row2-1][col2-1] &= 15;  // Flip the 5th bit back to indicate the card is unflipped
        }

        // Clear Screen
        system("clear");
    }

    // Print Final Board
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] < 10) {
                printf(" %d ", board[i][j]);
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("Congratulations! You have won the game!\n");
    return 0;
}