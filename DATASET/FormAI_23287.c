//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingo[5][5];
    int i, j, num, cnt, bingo_cnt;
    srand(time(NULL));
    
    // initialize the Bingo card
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                bingo[i][j] = 0; // center is free spot
            } else {
                num = rand() % 15 + (j * 15) + 1;
                for (cnt = 0; cnt < j; cnt++) {
                    if (bingo[i][cnt] == num) break; // check for duplicates
                }
                if (cnt == j) {
                    bingo[i][j] = num;
                } else {
                    j--; // try again
                }
            }
        }
    }
    
    bingo_cnt = 0;
    // start the game
    while (bingo_cnt < 5) {
        printf("B I N G O\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("%2d", bingo[i][j]);
                }
                if (i == j) {
                    if (bingo[i][j] == 0) {
                        cnt++;
                    }
                }
            }
            printf("\n");
        }
        
        // ask for input
        printf("Enter a number (0 to quit): ");
        scanf("%d", &num);
        if (num == 0) break;
        
        // mark the input number
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == num) {
                    bingo[i][j] = 0;
                    goto bingo_check;
                }
            }
        }
        printf("%d is not on the card.\n", num);
        continue;
        
        // check for a bingo
        bingo_check:
        cnt = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingo[i][j] == 0) {
                    if (i == j) {
                        cnt++; // diagonal #1
                    } else if (i + j == 4) {
                        cnt++; // diagonal #2
                    }
                }
            }
            if (cnt == 5) {
                bingo_cnt++;
                printf("BINGO!!! You got %d bingos!\n", bingo_cnt);
                if (bingo_cnt == 5) {
                    printf("Congratulations!!! You won the game!\n");
                    return 0;
                }
                break;
            }
            cnt = 0;
        }
    }
    printf("Thanks for playing! Goodbye!\n");
    return 0;
}