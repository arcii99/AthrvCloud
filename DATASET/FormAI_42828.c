//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Visionary C Game Program\n");
    printf("------------------------------------\n");
    printf("You have 10 seconds to guess a number between 1 to 10.\n");

    srand(time(0));
    int r = (rand() % 10) + 1;
    int tries = 0;
    clock_t start_time = clock();

    while ((clock() - start_time) / CLOCKS_PER_SEC < 10) {
        int num;
        printf("Guess: ");
        scanf("%d", &num);
        tries++;

        if (num == r) {
            printf("Congratulations, you guessed the number in %d tries!\n", tries);
            return 0;
        } else if (num < r) {
            printf("The number is higher, try again.\n");
        } else {
            printf("The number is lower, try again.\n");
        }
    }

    printf("Sorry, time's up. The number was %d\n", r);
    return 0;
}