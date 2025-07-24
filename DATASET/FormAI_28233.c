//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A Haunted House Simulator Program

int main() {
    srand(time(NULL)); // Initialize random seed
    printf("----------------------------------\n");
    printf("Welcome to the Haunted House!\n");
    printf("----------------------------------\n\n");

    // Set up variables to keep track of user's progress
    int hallway = 0; // 0 means user is in starting room
    int bathroomVisited = 0; // 0 means bathroom has not been visited
    int bedroomVisited = 0; // 0 means bedroom has not been visited
    int kitchenVisited = 0; // 0 means kitchen has not been visited
    int livingRoomVisited = 0; // 0 means living room has not been visited
    int basementVisited = 0; // 0 means basement has not been visited
    int exitVisited = 0; // 0 means exit has not been visited

    // Start main game loop
    while (1) {
        printf("You are in the ");

        // Print out the name of the current room
        switch (hallway) {
            case 0:
                printf("starting room.\n");
                break;
            case 1:
                printf("bathroom.\n");
                break;
            case 2:
                printf("bedroom.\n");
                break;
            case 3:
                printf("kitchen.\n");
                break;
            case 4:
                printf("living room.\n");
                break;
            case 5:
                printf("basement.\n");
                break;
            case 6:
                printf("exit.\n");
                break;
        }

        printf("What would you like to do?\n");
        printf("1. Move to a different room\n");
        printf("2. Look around the room\n");
        printf("3. Try to open the door to the next room\n");

        int choice;
        scanf("%d", &choice); // Get user's choice

        switch (choice) {
            case 1:
                // Randomly select a new room to move to (excluding starting room and previously visited rooms)
                int newRoom;
                do {
                    newRoom = rand() % 6 + 1; // Generate a random number between 1 and 6 (inclusive)
                } while (newRoom == hallway || newRoom == exitVisited || ((newRoom == 1 && bathroomVisited == 1) || (newRoom == 2 && bedroomVisited == 1) || (newRoom == 3 && kitchenVisited == 1) || (newRoom == 4 && livingRoomVisited == 1) || (newRoom == 5 && basementVisited == 1)));

                hallway = newRoom; // Update user's progress

                // Print out a description of the new room
                switch (hallway) {
                    case 1:
                        printf("You have entered the bathroom. It smells like someone just used it.\n");
                        bathroomVisited = 1; // Mark bathroom as visited
                        break;
                    case 2:
                        printf("You have entered the bedroom. The bed is unmade and the dresser drawers are slightly open.\n");
                        bedroomVisited = 1; // Mark bedroom as visited
                        break;
                    case 3:
                        printf("You have entered the kitchen. The sink is full of dirty dishes and the fridge has a foul odor coming from it.\n");
                        kitchenVisited = 1; // Mark kitchen as visited
                        break;
                    case 4:
                        printf("You have entered the living room. The TV is on and the couch looks like someone was just sitting on it.\n");
                        livingRoomVisited = 1; // Mark living room as visited
                        break;
                    case 5:
                        printf("You have entered the basement. The light bulb is flickering and there's a cold draft.\n");
                        basementVisited = 1; // Mark basement as visited
                        break;
                    case 6:
                        printf("You have exited the haunted house. Congratulations!\n");
                        exitVisited = 1; // Mark exit as visited
                        return 0; // End the program
                }
                break;
            case 2:
                // Print out a description of the current room
                switch (hallway) {
                    case 0:
                        printf("The starting room is empty and has not been lived in for a while.\n");
                        break;
                    case 1:
                        printf("The bathroom has a shower curtain that is closed. You can hear water dripping from the faucet.\n");
                        break;
                    case 2:
                        printf("The bedroom has a queen-sized bed and a nightstand with a lamp. There is a picture frame on the wall that is tilted.\n");
                        break;
                    case 3:
                        printf("The kitchen has a gas stove, refrigerator, and a sink full of scraps. There's a note on the fridge which says 'You will not leave'.\n");
                        break;
                    case 4:
                        printf("The living room has a dusty rug on the floor and a few old chairs. You can hear voices coming from outside.\n");
                        break;
                    case 5:
                        printf("The basement has a lot of dust and cobwebs everywhere. You can barely see your way around.\n");
                        break;
                }
                break;
            case 3:
                // Try to open the door to the next room (if it's not the exit)
                if (hallway != 6) {
                    printf("The door is locked.\n");
                } else {
                    printf("You have successfully opened the door and escaped the haunted house. Congratulations!\n");
                    exitVisited = 1; // Mark exit as visited
                    return 0; // End the program
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    // The code should never get to this point, but this is here just in case
    return 0;
}