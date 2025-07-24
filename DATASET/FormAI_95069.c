//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    int bingo[5][5]; // create a 2D array to hold Bingo card values
    int i, j, num, row, col, count, gameover;
    
    // initialize the Bingo card with random values between 1 and 75
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            num = rand() % 75 + 1;
            bingo[i][j] = num;
        }
    }
    
    // mark the center square as a free space
    bingo[2][2] = ' ';
    
    // print out the Bingo card
    printf("Your Bingo card:\n");
    for (i = 0; i < 5; i++) {
        printf("+----+----+----+----+----+\n");
        for (j = 0; j < 5; j++) {
            if (bingo[i][j] < 10) {
                printf("|  %d ", bingo[i][j]);
            } else {
                printf("| %d ", bingo[i][j]);
            }
        }
        printf("|\n");
    }
    printf("+----+----+----+----+----+\n");
    
    // start the game loop
    count = 0;
    gameover = 0;
    while (!gameover) {
        // get a random number between 1 and 75
        num = rand() % 75 + 1;
        printf("The next number is: %d\n", num);
        count++;
        
        // check if the number is on the Bingo card and mark it if it is
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == num) {
                    bingo[i][j] = ' ';
                    printf("Number %d is on your card!\n", num);
                    // check for a Bingo in this row, column, or diagonal
                    row = 1;
                    col = 1;
                    if (i == j) { // diagonal from top-left to bottom-right
                        for (int k = 0; k < 5; k++) {
                            if (bingo[k][k] != ' ') {
                                row = 0;
                                col = 0;
                                break;
                            }
                        }
                    }
                    if (i + j == 4) { // diagonal from top-right to bottom-left
                        for (int k = 0; k < 5; k++) {
                            if (bingo[k][4-k] != ' ') {
                                row = 0;
                                col = 0;
                                break;
                            }
                        }
                    }
                    if (row) { // check row i
                        row = 0;
                        for (int k = 0; k < 5; k++) {
                            if (bingo[i][k] != ' ') {
                                row = 1;
                                break;
                            }
                        }
                    }
                    if (col) { // check column j
                        col = 0;
                        for (int k = 0; k < 5; k++) {
                            if (bingo[k][j] != ' ') {
                                col = 1;
                                break;
                            }
                        }
                    }
                    // if we have a Bingo, end the game
                    if (row == 0 || col == 0) {
                        printf("Bingo! You won in %d turns!\n", count);
                        gameover = 1;
                        break;
                    }
                }
            }
            if (gameover) {
                break;
            }
        }
    }
    return 0;
}