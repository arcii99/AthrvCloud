//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Haunted House Simulator!\n");

    srand(time(NULL));
    int decision = rand() % 2;
    if (decision == 0) {
        printf("You walk into the front door of the haunted house. It creaks shut behind you and you realize the handle has fallen off. You're trapped!\n");
    } else {
        printf("You decide to turn around and leave the haunted house, but you find the door has disappeared. You're trapped!\n");
    }

    printf("You start to explore the house...\n");

    int roomNumber = 1;
    while (roomNumber < 6) {
        printf("\n\nRoom %d\n", roomNumber);

        srand(time(NULL) + roomNumber);
        int ghostEncounter = rand() % 2;

        if (ghostEncounter == 0) {
            printf("The room is empty. You feel a little disappointed that you didn't encounter a ghost.\n");
        } else {
            printf("You encounter a ghost! It starts to chase you...\n\n");
            int escape = rand() % 2;
            if (escape == 0) {
                printf("You run as fast as you can and manage to escape the ghost. You continue exploring the haunted house.\n");
            } else {
                printf("The ghost catches up to you and... GAME OVER!\n");
                exit(1);
            }
        }

        roomNumber++;
    }

    printf("\n\nYou've explored all of the rooms and survived the haunted house! Congratulations!\n");
    return 0;
}