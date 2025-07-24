//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are brave to enter this house of horrors!\n");
    printf("Beware - anything could happen.\n");

    char name[30];
    printf("\nPlease enter your name: ");
    scanf("%s", name);

    printf("\nHello %s, let's begin...\n", name);

    int choice, doors;
    srand(time(NULL));

    printf("\nYou have entered the haunted house...\n");

    do {
        printf("\nAhead are 3 doors...\n");
        printf("Which door will you choose? (1, 2, or 3): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    } while (choice < 1 || choice > 3);

    doors = rand() % 3 + 1;

    printf("\nYou have chosen door number %d...\n", choice);
    printf("Behind door number %d is...\n", doors);

    if (doors == choice) {
        printf("Nothing but darkness and silence...\n");
    } else {
        printf("A terrible monster that devours you alive!!!\n");
        printf("Game over %s, better luck next time...\n", name);
        return 0;
    }

    printf("\nCongratulation %s, you have successfully exited the Haunted House alive!!!\n", name);

    return 0;
}