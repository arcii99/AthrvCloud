//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
/* Haunted House Simulator */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define ROOM_DESC_MAX_LEN 100
#define ITEM_DESC_MAX_LEN 50
#define NUM_ROOMS 6
#define NUM_ITEMS 4

/* Room Struct */
typedef struct Room {
    char description[ROOM_DESC_MAX_LEN];
    bool isLit;
    struct Room* connections[4]; // north, south, east, west
} Room;

/* Item Struct */
typedef struct Item {
    char description[ITEM_DESC_MAX_LEN];
    bool isLit;
} Item;

/* Function prototypes */
void createRooms(Room roomArray[]);
void createConnections(Room roomArray[]);
void createItems(Item itemArray[]);
void playGame(Room roomArray[], Item itemArray[]);

/* Main function */
int main() {
    Room roomArray[NUM_ROOMS];
    Item itemArray[NUM_ITEMS];
    srand(time(NULL)); // seed the random function

    createRooms(roomArray);
    createConnections(roomArray);
    createItems(itemArray);
    playGame(roomArray, itemArray);

    return 0;
}

/* Function to create the rooms and their descriptions */
void createRooms(Room roomArray[]) {
    strcpy(roomArray[0].description, "You find yourself in a dusty entryway. The only thing in here is a coat rack.");
    roomArray[0].isLit = true;
    strcpy(roomArray[1].description, "You've entered the living room. The furniture is covered in dust.");
    roomArray[1].isLit = false;
    strcpy(roomArray[2].description, "You've stumbled into a dimly lit dining room. There's a large table in the center.");
    roomArray[2].isLit = false;
    strcpy(roomArray[3].description, "You're now in the kitchen. It smells musty and there's a sink full of dishes.");
    roomArray[3].isLit = false;
    strcpy(roomArray[4].description, "This is the bedroom. There's a four-poster bed in the center of the room.");
    roomArray[4].isLit = false;
    strcpy(roomArray[5].description, "You've found a creepy cellar. There are cobwebs everywhere and it's hard to see.");
    roomArray[5].isLit = false;
}

/* Function to create the connections between the rooms */
void createConnections(Room roomArray[]) {
    // Set up the connections for the entryway
    roomArray[0].connections[0] = &roomArray[1]; // north
    roomArray[0].connections[1] = NULL; // south
    roomArray[0].connections[2] = NULL; // east
    roomArray[0].connections[3] = NULL; // west
    
    // Set up the connections for the living room
    roomArray[1].connections[0] = &roomArray[3]; // north
    roomArray[1].connections[1] = &roomArray[0]; // south
    roomArray[1].connections[2] = &roomArray[2]; // east
    roomArray[1].connections[3] = NULL; // west
    
    // Set up the connections for the dining room
    roomArray[2].connections[0] = NULL; // north
    roomArray[2].connections[1] = NULL; // south
    roomArray[2].connections[2] = NULL; // east
    roomArray[2].connections[3] = &roomArray[1]; // west
    
    // Set up the connections for the kitchen
    roomArray[3].connections[0] = NULL; // north
    roomArray[3].connections[1] = &roomArray[1]; // south
    roomArray[3].connections[2] = &roomArray[4]; // east
    roomArray[3].connections[3] = NULL; // west
    
    // Set up the connections for the bedroom
    roomArray[4].connections[0] = NULL; // north
    roomArray[4].connections[1] = NULL; // south
    roomArray[4].connections[2] = &roomArray[5]; // east
    roomArray[4].connections[3] = &roomArray[3]; // west
    
    // Set up the connections for the cellar
    roomArray[5].connections[0] = &roomArray[4]; // north
    roomArray[5].connections[1] = NULL; // south
    roomArray[5].connections[2] = NULL; // east
    roomArray[5].connections[3] = NULL; // west
}

/* Function to create the items in the rooms */
void createItems(Item itemArray[]) {
    strcpy(itemArray[0].description, "A dust-covered key");
    itemArray[0].isLit = true;
    strcpy(itemArray[1].description, "A rusty old lantern");
    itemArray[1].isLit = false;
    strcpy(itemArray[2].description, "A tattered book");
    itemArray[2].isLit = true;
    strcpy(itemArray[3].description, "A potion bottle");
    itemArray[3].isLit = false;
}

/* Function to play the game */
void playGame(Room roomArray[], Item itemArray[]) {
    int currentPlayerLocation = 0;
    int numItemsFound = 0;
    int litItemsCount = 0;
    bool gameWon = false;

    printf("\nWelcome to the Haunted House! Can you find all the items and escape?\n\n");

    while (!gameWon) {
        if (roomArray[currentPlayerLocation].isLit) {
            litItemsCount = 0; // reset the count of lit items in each lit room
            printf("%s\n\n", roomArray[currentPlayerLocation].description);
            printf("You see the following items here:\n");
            for (int i = 0; i < NUM_ITEMS; i++) {
                if (roomArray[currentPlayerLocation].isLit && itemArray[i].isLit) {
                    printf("- %s\n", itemArray[i].description);
                    litItemsCount++;
                }
            }
            printf("\n");

            if (litItemsCount > 0) {
                char input[ITEM_DESC_MAX_LEN];
                printf("Enter an item name to pick it up, or type \"help\" to see all possible actions.\n");
                fgets(input, ITEM_DESC_MAX_LEN, stdin);
                strtok(input, "\n"); // remove trailing newline character from input
                printf("\n");

                if (strcmp(input, "help") == 0) {
                    printf("Possible actions:\n");
                    printf("- Enter compass direction (north, south, east, west) to move to another room\n");
                    printf("- Enter item name to pick it up if it's in the current room\n");
                    printf("- Enter \"quit\" to exit the game\n\n");
                }
                else if (strcmp(input, "quit") == 0) {
                    printf("Game over!\n");
                    return;
                }
                else {
                    bool itemFound = false;
                    for (int i = 0; i < NUM_ITEMS; i++) {
                        if (strcmp(input, itemArray[i].description) == 0) {
                            numItemsFound++;
                            itemArray[i].isLit = false; // remove item from room once it's picked up
                            itemFound = true;
                            printf("You picked up the %s!\n\n", itemArray[i].description);
                            break;
                        }
                    }
                    if (!itemFound) {
                        printf("That item is not in this room. Try again.\n\n");
                    }
                }
            }
        }
        else {
            printf("It's too dark! You can't see anything. Try finding a light source.\n\n");
        }

        if (numItemsFound == NUM_ITEMS) {
            printf("Congratulations! You found all the items and escaped the haunted house!\n");
            gameWon = true;
        }
        else {
            char input[ITEM_DESC_MAX_LEN];
            printf("Enter compass direction to move to another room.\n");
            fgets(input, ITEM_DESC_MAX_LEN, stdin);
            strtok(input, "\n"); // remove trailing newline character from input
            printf("\n");

            bool directionFound = false;
            for (int i = 0; i < 4; i++) {
                if (roomArray[currentPlayerLocation].connections[i] != NULL && strcmp(input, "north") == 0 && i == 0) {
                    currentPlayerLocation = (int)(roomArray[currentPlayerLocation].connections[i] - &roomArray[0]); // subtract pointer to first room and cast to int
                    directionFound = true;
                    printf("Moving north...\n\n");
                    break;
                }
                else if (roomArray[currentPlayerLocation].connections[i] != NULL && strcmp(input, "south") == 0 && i == 1) {
                    currentPlayerLocation = (int)(roomArray[currentPlayerLocation].connections[i] - &roomArray[0]);
                    directionFound = true;
                    printf("Moving south...\n\n");
                    break;
                }
                else if (roomArray[currentPlayerLocation].connections[i] != NULL && strcmp(input, "east") == 0 && i == 2) {
                    currentPlayerLocation = (int)(roomArray[currentPlayerLocation].connections[i] - &roomArray[0]);
                    directionFound = true;
                    printf("Moving east...\n\n");
                    break;
                }
                else if (roomArray[currentPlayerLocation].connections[i] != NULL && strcmp(input, "west") == 0 && i == 3) {
                    currentPlayerLocation = (int)(roomArray[currentPlayerLocation].connections[i] - &roomArray[0]);
                    directionFound = true;
                    printf("Moving west...\n\n");
                    break;
                }
            }
            if (!directionFound) {
                printf("Invalid direction. Try again.\n\n");
            }
        }
    }
}