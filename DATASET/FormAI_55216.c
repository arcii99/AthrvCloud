//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int current_room = 0; // starting room
int key = 0; // player's inventory
int done = 0; // flag for game completion

// function to display the room description and available actions
void display_room() {
    switch(current_room) {
        case 0: // starting room
            printf("You find yourself in a dimly lit room.\n");
            printf("You see a door to the north.\n");
            printf("What do you do?\n");
            printf("1. Go north\n");
            printf("2. Check the room more closely\n");
            break;
        case 1: // room with key
            printf("You see a key on the floor.\n");
            printf("You also see a door to the south and a door to the east.\n");
            printf("What do you do?\n");
            printf("1. Go south\n");
            printf("2. Go east\n");
            printf("3. Pick up key\n");
            break;
        case 2: // room with locked door
            printf("You see a locked door to the north.\n");
            printf("You also see a door to the south.\n");
            if(key == 1) { // player has key, can unlock door
                printf("What do you do?\n");
                printf("1. Go north (use key)\n");
            } else { // player does not have key, cannot unlock door
                printf("You need a key to open this door.\n");
                printf("What do you do?\n");
            }
            printf("2. Go south\n");
            break;
        case 3: // room with exit
            printf("You see the exit door to the east.\n");
            printf("What do you do?\n");
            printf("1. Go east\n");
            break;
    }
}

int main() {
    while(!done) { // keep playing until game is completed
        display_room(); // display room description and available actions
        int choice;
        scanf("%d", &choice); // get player's choice
        system("clear"); // clear screen for next room display

        switch(current_room) {
            case 0: // starting room
                if(choice == 1) { // go north
                    current_room = 1; // move to next room
                } else if(choice == 2) { // check room closely
                    printf("You see nothing of interest.\n");
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 1: // room with key
                if(choice == 1) { // go south
                    current_room = 0;
                } else if(choice == 2) { // go east
                    current_room = 2;
                } else if(choice == 3) { // pick up key
                    printf("You pick up the key.\n");
                    key = 1; // add key to player's inventory
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 2: // room with locked door
                if(choice == 1 && key == 1) { // go north with key
                    printf("You unlock the door and go through it.\n");
                    current_room = 3;
                } else if(choice == 2) { // go south
                    current_room = 1;
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case 3: // room with exit
                if(choice == 1) { // go east
                    printf("You have successfully escaped the room!\n");
                    done = 1; // set completion flag to end game
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            default:
                printf("An error occurred.\n");
                exit(1);
                break;
        }
    }

    return 0;
}