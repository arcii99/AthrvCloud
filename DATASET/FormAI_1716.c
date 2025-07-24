//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, bingo[5][5], num, check[25] = {0}, count = 0;
    char *mark = "X ";
    srand(time(NULL));

    // Initialize bingo board with random numbers
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            num = (j==2 && i==2) ? 0 : (rand() % 15) + (j * 15) + 1;
            bingo[i][j] = num;
            printf("%2d ", num);
        }
        printf("\n");
    }

    // Start game loop
    printf("\nLet's start playing BINGO!\n");
    while (count < 25) {
        printf("\nEnter a number between 1 and 75: ");
        scanf("%d", &num);

        // Check if number already called
        if (num < 1 || num > 75 || check[num-1] == 1) {
            printf("\nInvalid or duplicate number. Please try again.\n");
            continue;
        }
        check[num-1] = 1;

        // Check if number is on bingo board
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) {
                if (bingo[i][j] == num) {
                    printf("\n%sYou have marked %d on the bingo board.\n", mark, num);
                    bingo[i][j] = 0;
                    count++;

                    // Check for bingo
                    if (count >= 5) {
                        // Check rows
                        for(i=0; i<5; i++) {
                            for(j=0; j<5; j++) {
                                if (bingo[i][j] != 0) {
                                    break;
                                }
                            }
                            if (j == 5) {
                                printf("\nBINGO!\n");
                                return 0;
                            }
                        }

                        // Check columns
                        for(i=0; i<5; i++) {
                            for(j=0; j<5; j++) {
                                if (bingo[j][i] != 0) {
                                    break;
                                }
                            }
                            if (j == 5) {
                                printf("\nBINGO!\n");
                                return 0;
                            }
                        }

                        // Check diagonals
                        if (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) {
                            printf("\nBINGO!\n");
                            return 0;
                        }
                        if (bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0) {
                            printf("\nBINGO!\n");
                            return 0;
                        }
                    }
                    break;
                }
            }
        }
        if (i == 5 && j == 5) {
            printf("\nNumber %d is not on the bingo board.\n", num);
        }
    }
    printf("\nAll numbers have been called! Game over.\n");

    return 0;
}