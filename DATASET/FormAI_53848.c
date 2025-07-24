//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned) time(NULL)); //Randomize the seed

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are exploring a haunted house and you must find the key to escape.\n");
    printf("You have three options at each step: Look for the key, Open a door, or Quit (q).\n");
    printf("Good luck!\n\n");

    int key_location = rand() % 10 + 1; //Randomly place the key in one of the rooms
    int current_room = 1;

    while (1) {
        //Check if the player has found the key
        if (current_room == key_location) {
            printf("You found the key! Congratulations, you escaped!\n");
            break;
        }

        //Print the current options
        printf("You are in room %d.\n", current_room);
        printf("What would you like to do?\n");
        printf("(L)ook for the key, (O)pen a door, (Q)uit: ");

        //Get the player's choice
        char choice;
        scanf(" %c", &choice);

        //Handle the player's choice
        switch (choice) {
            case 'L':
            case 'l':
                if (rand() % 3 == 0) { //1 in 3 chance of finding the key
                    printf("You found the key! Congratulations, you escaped!\n");
                    break;
                }
                else {
                    printf("You didn't find the key.\n");
                }
                break;

            case 'O':
            case 'o':
                //Randomly choose a new room to move to
                int new_room = rand() % 10 + 1;
                while (new_room == current_room) { //Make sure the new room is different from the current room
                    new_room = rand() % 10 + 1;
                }
                current_room = new_room;
                printf("You opened a door and moved to room %d.\n", current_room);
                break;

            case 'Q':
            case 'q':
                printf("You quit the game. Thanks for playing!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}