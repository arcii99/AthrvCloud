//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 75

/* function to get a random number between 1 and 75 */
int get_random_number() {
    return rand() % MAX_NUMBERS + 1;
}

int main() {
    int bingo_card[5][5];   // 5x5 bingo card
    int numbers[MAX_NUMBERS];   // array to keep track of numbers called
    int num_calls = 0;   // counter for number of calls

    // initialize random number generator
    srand(time(NULL));

    // fill bingo card with random numbers between 1 and 75
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            bingo_card[i][j] = get_random_number();
        }
    }

    // print out the bingo card
    printf("BINGO CARD:\n");
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%2d ", bingo_card[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // start calling numbers
    int number;
    do {
        // get a random number
        number = get_random_number();

        // check if number has been called before
        int found = 0;
        for (int i=0; i<num_calls; i++) {
            if (numbers[i] == number) {
                found = 1;
                break;
            }
        }

        // if new number, add to list
        if (!found) {
            numbers[num_calls++] = number;

            // print out the number called
            printf("Number called: %d\n", number);

            // check if number matches any on the bingo card
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    if (bingo_card[i][j] == number) {
                        bingo_card[i][j] = 0;   // mark as found
                    }
                }
            }

            // print out updated bingo card
            printf("BINGO CARD:\n");
            for (int i=0; i<5; i++) {
                for (int j=0; j<5; j++) {
                    printf("%2d ", bingo_card[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            // check for winning condition
            int row, col, diag1, diag2;
            for (int i=0; i<5; i++) {
                row = col = 1;
                for (int j=0; j<5; j++) {
                    if (bingo_card[i][j] != 0) {
                        row = 0;
                    }
                    if (bingo_card[j][i] != 0) {
                        col = 0;
                    }
                }
                if (row || col) {
                    printf("BINGO!!!\n");
                    exit(0);
                }
            }
            diag1 = diag2 = 1;
            for (int i=0; i<5; i++) {
                if (bingo_card[i][i] != 0) {
                    diag1 = 0;
                }
                if (bingo_card[i][4-i] != 0) {
                    diag2 = 0;
                }
            }
            if (diag1 || diag2) {
                printf("BINGO!!!\n");
                exit(0);
            }
        }
    } while (1);   // keep calling until winning condition is met
}