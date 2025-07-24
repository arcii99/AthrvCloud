//FormAI DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int i, j, a, b, temp;
    int count = 0;
    int cards[ROWS][COLS] = {0};
    int flips[2][2] = {{-1, -1}, {-1, -1}};

    srand(time(NULL));
    
    // Set each card with their corresponding pair
    for (int k = 1; k <= (ROWS * COLS) / 2; k++) {
        for (int l = 0; l < 2; l++) {
            do {
                i = rand() % ROWS;
                j = rand() % COLS;
            } while(cards[i][j] != 0);
            cards[i][j] = k;
        }
    }

    // Shuffle the cards
    for (int k = 0; k < ROWS * COLS; k++) {
        do {
            a = rand() % ROWS;
            b = rand() % COLS;
        } while (a == i && b == j);
        temp = cards[i][j];
        cards[i][j] = cards[a][b];
        cards[a][b] = temp;
    }
    
    // Play until all cards are matched
    while (count < (ROWS * COLS) / 2) {
        // Print the current state of the game
        printf("   ");
        for (int k = 0; k < COLS; k++) {
            printf("%d ", k);
        }
        printf("\n");
        printf("---");
        for (int k = 0; k < COLS; k++) {
            printf("--");
        }
        printf("\n");

        for (int k = 0; k < ROWS; k++) {
            printf("%d |", k);
            for (int l = 0; l < COLS; l++) {
                if (cards[k][l] < 0) {
                    printf("X ");
                } else {
                    printf("%d ", cards[k][l]);
                }
            }
            printf("\n");
        }

        // Prompt user to choose two cards to flip
        for (int k = 0; k < 2; k++) {
            do {
                printf("Enter row and column of card %d to flip: ", k+1);
                scanf("%d %d", &flips[k][0], &flips[k][1]);
            } while (flips[k][0] < 0 || flips[k][0] >= ROWS || flips[k][1] < 0 || flips[k][1] >= COLS || cards[flips[k][0]][flips[k][1]] < 0);

            // Flip the chosen card
            cards[flips[k][0]][flips[k][1]] *= -1;
        }

        // Check if the chosen cards match
        if (cards[flips[0][0]][flips[0][1]] == cards[flips[1][0]][flips[1][1]]) {
            printf("You found a match!\n");
            count++;
        } else {
            printf("Sorry, not a match\n");
            // Flip the chosen cards back over
            cards[flips[0][0]][flips[0][1]] *= -1;
            cards[flips[1][0]][flips[1][1]] *= -1;
        }
    }

    printf("Congratulations, you found all the matches!\n");

    return 0;
}