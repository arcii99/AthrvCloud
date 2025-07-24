//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 200

int main() {
    srand(time(NULL)); // Seed for random numbers

    char conspiracies[MAX_CONSPIRACY_LENGTH];
    int num_players, i, j;

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("How many players are there? ");
    scanf("%d", &num_players);

    printf("\nGenerating conspiracy theories...\n\n");

    for (i = 1; i <= 3; i++) { // Generate three conspiracy theories
        printf("Conspiracy theory %d: ", i);

        for (j = 0; j < MAX_CONSPIRACY_LENGTH; j++) { // Generate random characters for the conspiracy theory
            if (rand() % 2 == 0) { // 50/50 chance for uppercase or lowercase letter
                conspiracies[j] = rand() % 26 + 'a';
            } else {
                conspiracies[j] = rand() % 26 + 'A';
            }
        }

        printf("%s\n", conspiracies);

        printf("Which player(s) does this theory target? ");
        for (j = 0; j < num_players; j++) {
            int target;
            scanf("%d", &target);
            printf("Player %d, ", target);
        }
        printf("you are the target(s) of the above conspiracy theory!\n\n");
    }

    printf("Thanks for playing the Random Conspiracy Theory Generator!\n");

    return 0;
}