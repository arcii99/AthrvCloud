//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess_num, tries=0;
    srand(time(0)); // seeding random number generator
    num = rand() % 100 + 1; // generating random number between 1 and 100

    printf("\nWelcome to the Haunted House Simulator Game!");
    printf("\n------------------------------------------");
    printf("\nGuess the mystery number between 1 and 100 to escape the haunted house.\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess_num);

        if (guess_num < num) {
            printf("\nToo low! Try again.");
            tries++;
        } else if (guess_num > num) {
            printf("\nToo high! Try again.");
            tries++;
        } else {
            printf("\nCongratulations! You escaped the haunted house in %d tries.", tries+1);
        }
    } while (guess_num != num);

    return 0;
}