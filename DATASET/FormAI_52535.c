//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int playerChoice;
    int ghostPosition;
    int isGameOver = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");

    while (!isGameOver) {
        printf("You are in a dark hallway in the haunted house. You can hear strange noises.\n");
        printf("What do you want to do?\n");
        printf("1. Walk Forward\n2. Turn Back\n");
        scanf("%d", &playerChoice);

        if (playerChoice == 1) {
            ghostPosition = rand() % 10 + 1;

            if (ghostPosition == 5) {
                printf("You hear a loud scream and a ghost appears in front of you!\n");
                printf("Game Over!\n");
                isGameOver = 1;
            }
            else {
                printf("You continue to walk down the hallway.\n");
            }
        }
        else if (playerChoice == 2) {
            printf("You turn back and run out of the house.\n");
            printf("You made it out alive!\n");
            isGameOver = 1;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}