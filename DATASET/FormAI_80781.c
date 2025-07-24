//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // To generate random output

    printf("*You are standing outside a haunted house*\n");
    printf("*Do you want to enter?*\n");
    printf("Type 1 for YES and 2 for NO\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("*You enter the haunted house*\n");
        printf("*The door slams shut behind you*\n");

        int chance = rand() % 2; // To generate random chance (0 or 1)

        if (chance == 0) { // Player loses
            printf("*Suddenly, you hear a loud noise from behind*\n");
            printf("*You turn around, but there is nothing there*\n");
            printf("*You feel cold breath on your neck*\n");
            printf("*You have been possessed by the ghost and lost the game*\n");
        } else { // Player wins
            printf("*You see a candle in the distance*\n");
            printf("*Do you want to follow it?*\n");
            printf("Type 1 for YES and 2 for NO\n");

            int choice2;
            scanf("%d", &choice2);

            if (choice2 == 1) {
                printf("*You follow the candle and find a key*\n");
                printf("*You use the key to unlock the door and escape*\n");
                printf("*Congratulations! You have won the game*\n");
            } else {
                printf("*You hear a scream behind you*\n");
                printf("*The ghost has caught up to you and you lose the game*\n");
            }
        }
    } else {
        printf("*You chickened out*\n");
        printf("*GAME OVER*\n");
    }

    return 0;
}