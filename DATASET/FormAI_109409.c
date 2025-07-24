//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random number between min and max
int randomInt(int min, int max){
    return rand() % (max - min + 1) + min;
}

// Function to simulate fright
void scream(){
    printf("Aahhhhhhhhh!!!!\n");
}

int main(){
    srand(time(NULL));  // Seed the random number generator

    // Define possible rooms and their descriptions
    char* rooms[] = {"Living Room", "Kitchen", "Bedroom", "Basement", "Attic"};
    char* roomDesc[] = {"a cozy room with a fireplace", 
                        "a cluttered room with old appliances",
                        "a dimly lit room with a queen-sized bed",
                        "a creepy room with rusted tools and chains",
                        "a dusty room filled with old furniture"};

    // Initialize player's location and game state
    int playerPos = randomInt(0, 4);
    bool gameWon = false;
    bool gameLost = false;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in the %s, %s.\n", rooms[playerPos], roomDesc[playerPos]);

    // Main game loop
    while(!gameWon && !gameLost){
        printf("\nWhat would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Search the room for items\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // Move to another room
                int newPos = randomInt(0, 4);
                scream();  // Simulate a scream to add to the atmosphere
                if(newPos == playerPos){
                    printf("You quickly realize that you are back in the same room.\n");
                } else {
                    playerPos = newPos;
                    printf("You move to the %s, %s.\n", rooms[playerPos], roomDesc[playerPos]);
                }
                break;
            case 2:
                // Search the current room for items
                int item = randomInt(1, 4);
                if(item == 1 || item == 2){
                    printf("You find an old book and a rusty key.\n");
                } else if(item == 3){
                    printf("You find an old photo album and some creepy dolls.\n");
                } else {
                    printf("You don't find anything useful.\n");
                }
                break;
            case 3:
                // Quit the game
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Check if player has won or lost
        if(playerPos == 4){
            printf("You climb up to the attic and find a way out of the house. Congratulations, you win!\n");
            gameWon = true;
        } else if(randomInt(1, 10) <= 4){
            scream();  // There is a 40% chance the player will get scared and lose the game
            printf("You get scared and run blindly through the house. You trip and hit your head, and everything goes dark...\n");
            gameLost = true;
        }

    }

    return 0;
}