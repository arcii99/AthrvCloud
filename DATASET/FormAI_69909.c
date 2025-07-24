//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE '*'

int main() {
    srand(time(NULL));
    int card[ROWS][COLS];

    // Initialize card with random numbers
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(j == 2 && i == 2) {
                card[i][j] = FREE_SPACE;
            } else {
                card[i][j] = rand() % 15 + i*15 + 1;
            }
        }
    }

    // Print card
    printf("/----------------------\\\n");
    for(int i=0; i<ROWS; i++) {
        printf("|");
        for(int j=0; j<COLS; j++) {
            printf("%02d|", card[i][j]);
        }
        printf("\n");
    }
    printf("\\----------------------/\n");

    // Initialize random numbers
    int drawnNumbers[75] = {0};
    for(int i=0; i<75; i++) {
        drawnNumbers[i] = i+1;
    }

    // Shuffle random numbers
    for(int i=0; i<75; i++) {
        int temp = drawnNumbers[i];
        int r = rand() % 75;
        drawnNumbers[i] = drawnNumbers[r];
        drawnNumbers[r] = temp;
    }

    // Draw first 75 numbers
    int current = 0;
    for(int i=0; i<75; i++) {
        printf("Press ENTER to draw a number\n");
        getchar();
        printf("Number %d: %d\n", i+1, drawnNumbers[i]);

        // Check if number is on card
        for(int j=0; j<ROWS; j++) {
            for(int k=0; k<COLS; k++) {
                if(card[j][k] == drawnNumbers[i]) {
                    card[j][k] = FREE_SPACE;
                    break;
                }
            }
        }

        // Print updated card
        printf("/----------------------\\\n");
        for(int j=0; j<ROWS; j++) {
            printf("|");
            for(int k=0; k<COLS; k++) {
                printf("%c%c|", card[j][k] == FREE_SPACE ? ' ' : (card[j][k] <= 9 ? ' ' : '\0'), card[j][k]);
            }
            printf("\n");
        }
        printf("\\----------------------/\n");

        // Check if game is over (bingo)
        int bingo = 0;
        for(int j=0; j<ROWS; j++) {
            int rowBingo = 1;
            int colBingo = 1;
            for(int k=0; k<COLS; k++) {
                rowBingo = rowBingo && (card[j][k] == FREE_SPACE); // check row
                colBingo = colBingo && (card[k][j] == FREE_SPACE); // check column
            }
            bingo = bingo || rowBingo || colBingo;
        }

        int diagBingo = (card[0][0] == FREE_SPACE && card[1][1] == FREE_SPACE && card[2][2] == FREE_SPACE && card[3][3] == FREE_SPACE && card[4][4] == FREE_SPACE) || (card[0][4] == FREE_SPACE && card[1][3] == FREE_SPACE && card[2][2] == FREE_SPACE && card[3][1] == FREE_SPACE && card[4][0] == FREE_SPACE);
        bingo = bingo || diagBingo;

        if(bingo) {
            printf("BINGO! You won in %d moves!\n", i+1);
            break;
        }

        current++;
    }

    return 0;
}