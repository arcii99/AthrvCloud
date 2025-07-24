//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room = 0, choice = 0, scare = 0;
    srand(time(NULL)); // seed random number generator with current time
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of a haunted house. Do you enter? (1 = Yes, 2 = No)\n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("You enter the house and find yourself in room 1.\n");
        while (room != 5 && scare < 3) { // while player hasn't reached the final room and hasn't been scared too many times
            printf("\nYou are in room %d. Which door do you choose? (1, 2 or 3)\n", room+1);
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You enter room %d and find a creepy painting on the wall.\n", room+2);
            } else if (choice == 2) {
                printf("You enter room %d and feel a chill run down your spine.\n", room+2);
                scare++;
            } else if (choice == 3) {
                printf("You enter room %d and find an old book on a table.\n", room+2);
            } else {
                printf("Invalid choice. Try again.\n");
                continue;
            }
            room++;
        }
        if (room == 5) {
            printf("\nCongratulations! You have made it through the haunted house!\n");
        } else {
            printf("\nOh no! You have been scared too many times and can no longer continue.\n");
        }
    } else {
        printf("You decide not to enter the haunted house. Goodbye!\n");
    }
    return 0;
}