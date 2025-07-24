//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int random_number = rand() % 10 + 1;
    int guess;
    int tries = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Try to guess the secret number between 1 and 10\n");
    printf("You have 3 chances before the house consumes your soul...\n\n");

    while (tries < 3) {
        printf("Guess #%d: ", tries+1);
        scanf("%d", &guess);

        if (guess > 10 || guess < 1) {
            printf("That's not a valid guess!\n");
            continue;
        }

        if (guess == random_number) {
            printf("\nCongratulations! You have escaped with your soul intact.\n");
            return 0;
        } else {
            if (guess < random_number) {
                printf("You hear some whispers... guess higher!\n");
            } else {
                printf("You feel a chill... guess lower!\n");
            }
        }

        tries++;
    }

    printf("\nYou have failed to escape the haunted house. Your soul belongs to the house now.\n");
    return 0;
}