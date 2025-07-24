//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing the game board
    char board[5][5] = {
        {'B', 'I', 'N', 'G', 'O'},
        {'7', '18', '42', '55', '70'},
        {'10', '21', 'FREE', '50', '68'},
        {'9', '25', '39', '59', '73'},
        {'4', '20', '36', '47', '63'}
    };

    // Printing the game board
    printf("\n\tWelcome to Medieval Bingo!\n\n");
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Generating random numbers for the caller
    srand(time(NULL));
    int numbers[75];
    for (int i=0; i<75; i++) {
        numbers[i] = i+1;
    }
    for (int i=0; i<75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Playing the game
    int count = 0;
    while (count < 75) {
        printf("Enter any key to draw a number:");
        getchar();

        printf("The number is %d.\n\n", numbers[count]);

        // Checking if the number is on the board
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (board[i][j] == numbers[count] + '0') {
                    board[i][j] = 'X';
                }
            }
        }

        // Printing the updated board
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                printf("%c\t", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // Checking if any player has won
        int row1 = 0, row2 = 0, row3 = 0, row4 = 0, row5 = 0;
        int col1 = 0, col2 = 0, col3 = 0, col4 = 0, col5 = 0;
        int diag1 = 0, diag2 = 0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (board[i][j] == 'X') {
                    if (i == 0) {
                        row1++;
                    } else if (i == 1) {
                        row2++;
                    } else if (i == 2) {
                        row3++;
                    } else if (i == 3) {
                        row4++;
                    } else {
                        row5++;
                    }
                    if (j == 0) {
                        col1++;
                    } else if (j == 1) {
                        col2++;
                    } else if (j == 2) {
                        col3++;
                    } else if (j == 3) {
                        col4++;
                    } else {
                        col5++;
                    }
                    if (i == j) {
                        diag1++;
                    }
                    if (i+j == 4) {
                        diag2++;
                    }
                }
            }
        }
        if (row1 == 5 || row2 == 5 || row3 == 5 || row4 == 5 || row5 == 5 ||
            col1 == 5 || col2 == 5 || col3 == 5 || col4 == 5 || col5 == 5 ||
            diag1 == 5 || diag2 == 5) {
            printf("Congratulations! You have won Medieval Bingo!\n");
            return 0;
        }

        count++;
    }

    printf("Sorry, all numbers have been drawn. You did not win. Better luck next time!\n");

    return 0;
}