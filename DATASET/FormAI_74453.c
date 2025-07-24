//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int board[5][5]; // initialise the board with zeroes
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }
    
    printf("Starting game of C Bingo Simulator...\n");
    
    while (1) { // keep playing until someone wins
        int num = rand() % 25 + 1; // generate a random number between 1 and 25
        
        printf("The next number is: %d\n", num);
        
        // check the board for the number
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1; // mark the number as found
                }
            }
        }
        
        // print the board
        printf("\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == -1) {
                    printf("X ");
                }
                else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
        
        // check if anyone has won
        int rows[5] = {0};
        int cols[5] = {0};
        int diag1 = 0;
        int diag2 = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == -1) {
                    rows[i]++;
                    cols[j]++;
                    if (i == j) {
                        diag1++;
                    }
                    if (i + j == 4) {
                        diag2++;
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            if (rows[i] == 5 || cols[i] == 5 || diag1 == 5 || diag2 == 5) {
                printf("BINGO! Player wins!\n");
                return 0;
            }
        }
    }
}