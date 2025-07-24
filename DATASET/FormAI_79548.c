//FormAI DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    /* Initialize random seed */
    srand(time(NULL));

    /* Generate random numbers between 1 and 6 */
    int dieOne = rand() % 6 + 1;
    int dieTwo = rand() % 6 + 1;
    int sum = dieOne + dieTwo;

    /* Output dice rolls */
    printf("Player 1 rolls: %d + %d = %d\n", dieOne, dieTwo, sum);

    /* Determine game outcome based on sum */
    if (sum == 7 || sum == 11) {
        printf("Player 1 wins!\n");
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("Player 1 loses!\n");
    } else {
        /* Continues rolling until a win or loss condition is met */
        int point = sum;
        printf("Point is %d\n", point);
        do {
            dieOne = rand() % 6 + 1;
            dieTwo = rand() % 6 + 1;
            sum = dieOne + dieTwo;
            printf("Player 1 rolls again: %d + %d = %d\n", dieOne, dieTwo, sum);
        } while (sum != point && sum != 7);

        /* Output winning/losing message based on final sum */
        if (sum == point) {
            printf("Player 1 wins!\n");
        } else {
            printf("Player 1 loses!\n");
        }
    }

    return 0;
}