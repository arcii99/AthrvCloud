//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define ROOMS 4

int main(void) {
    srand(time(NULL)); // seed random number generator
    int currentRoom = 0;
    int previousRoom = -1;
    int attempts = 0;
    int ghostAppeared = 0;

    // create array of rooms
    char rooms[ROOMS][50] = {
        "You enter a dark, musty room with a single door.",
        "You enter a room with cobwebs in every corner.",
        "You enter a room with a creaky wooden floor.",
        "You enter a room with a portrait of a creepy looking person on the wall."
    };

    // print first room description
    printf("%s\n", rooms[currentRoom]);

    // loop until user reaches the final room
    while(currentRoom < ROOMS-1) {
        // get user input
        char input[50] = "";
        printf("Which direction do you want to go? ");
        fgets(input, 50, stdin);
        input[strcspn(input, "\r\n")] = '\0'; // remove newline character

        // check if user input is valid
        if(strcmp(input, "north") != 0 && strcmp(input, "south") != 0 && strcmp(input, "east") != 0 && strcmp(input, "west") != 0) {
            printf("Invalid direction, please try again.\n");
            continue;
        }

        // randomly determine if ghost will appear
        int chance = rand() % 10;
        if(chance < 2 && previousRoom != currentRoom && attempts < 3) { // ghost appears
            printf("You suddenly feel a cold chill run down your spine. ");
            printf("A ghostly apparition materializes in front of you!\n");
            attempts++;
            ghostAppeared = 1;
        }
        else {
            attempts = 0;
            ghostAppeared = 0;
        }

        // move to new room
        if(strcmp(input, "north") == 0) {
            currentRoom++;
            printf("%s\n", rooms[currentRoom]);
        }
        else if(strcmp(input, "south") == 0) {
            currentRoom--;
            printf("%s\n", rooms[currentRoom]);
        }
        else if(strcmp(input, "east") == 0) {
            currentRoom += 2;
            printf("%s\n", rooms[currentRoom]);
        }
        else if(strcmp(input, "west") == 0) {
            currentRoom -= 2;
            printf("%s\n", rooms[currentRoom]);
        }

        // check if user found key
        if(currentRoom == ROOMS-1) {
            printf("You found the key!\n");
            printf("You quickly turn around and run back the way you came.\n");
        }

        previousRoom = currentRoom;
    }

    // print final message
    if(ghostAppeared) {
        printf("You narrowly escape the ghost and exit the haunted house, ");
    }
    else {
        printf("You exit the haunted house, ");
    }
    printf("clutching the key tightly in your hand.\n");

    return 0;
}