//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {
    int i,j,k;
    int bingoCard[ROWS][COLUMNS] = {0};
    int numDrawn;
    int hasWon = 0;
    int numBingo = 0;

    // Generate random numbers for bingo card
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            if(j == 2 && i == 2) bingoCard[i][j] = 0;
            else {
                bingoCard[i][j] = rand() % 15 + (j * 15) + 1;
                for(k = 0; k < j; k++) {
                    if(bingoCard[i][k] == bingoCard[i][j]) {
                        j--;
                        break;
                    }
                }
            }
        }
    }

    printf("Welcome to the Bingo Simulator!\n");
    printf("Your bingo card:\n");
    printf("-----------------\n");

    // Display the bingo card
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%02d\t", bingoCard[i][j]);
        }
        printf("\n");
    }

    printf("-----------------\n");

    // Draw numbers and check for bingo
    while(!hasWon) {
        printf("Enter the drawn number (0 to quit): ");
        scanf("%d", &numDrawn);

        if(numDrawn == 0) {
            printf("Thank you for playing Bingo Simulator!\n");
            break;
        }

        // Check the bingo card for the drawn number
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLUMNS; j++) {
                if(bingoCard[i][j] == numDrawn) {
                    bingoCard[i][j] = 0;
                    numBingo++;
                }
            }
        }

        // Check for bingo
        if(numBingo == 24) {
            printf("BINGO!! You have won!\n");
            hasWon = 1;
            break;
        }

        // Display the updated bingo card
        printf("Your updated bingo card:\n");
        printf("-----------------\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLUMNS; j++) {
                printf("%02d\t", bingoCard[i][j]);
            }
            printf("\n");
        }
        printf("-----------------\n");
        
    }

    return 0;
}