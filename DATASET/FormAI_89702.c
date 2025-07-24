//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int count = 0; // Counter for number of rooms visited
    int choice; // User's choice of direction to go
    srand(time(0)); // Generate random seed based on current time

    printf("Welcome to the haunted house!\n");
    printf("You find yourself in the foyer.\n");

    while (count < 5) {
        printf("Which way would you like to go?\n");
        printf("1. Left\n2. Right\n3. Straight\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You turn left and find yourself in a dark hallway.\n");
                break;
            case 2:
                printf("You turn right and see a staircase leading up.\n");
                break;
            case 3:
                printf("You walk straight and find yourself in a dimly lit room.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        // 50% chance of encountering a ghost in each room
        if (rand() % 2 == 0) {
            printf("BOO! A ghost appears and scares you!\n");
        }

        count++; // Increment room counter
    }

    printf("Congratulations, you have made it out of the haunted house!\n");

    return 0;
}