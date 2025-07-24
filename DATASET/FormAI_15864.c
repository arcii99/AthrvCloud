//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struct for inventory items
typedef struct {
    char name[50];
} Item;

// Struct for game rooms
typedef struct {
    char name[50];
    char description[500];
    Item item;
    int north, south, east, west;
} Room;

// Function declarations
void printDescription(char *description);
void printExit(Room room);
void printInventory(Item item);
bool checkWin(Item item);

int main() {
    // Set up game rooms
    Room rooms[4] = {
        {"Living Room", "You are in a cozy living room with a fireplace. To the north is the kitchen.", {"", NULL}, 1, -1, -1, -1},
        {"Kitchen", "You are in a modern kitchen with stainless steel appliances. To the south is the living room and to the east is the backyard.", {"Key", NULL}, -1, 0, 2, -1},
        {"Backyard", "You are in a spacious backyard with a pool. To the west is the kitchen.", {"", NULL}, -1, -1, -1, 1},
        {"Bedroom", "You are in a comfortable bedroom with a queen size bed. You have won the game!", {"", NULL}, -1, -1, -1, -1}
    };
    // Set up starting room
    Room currentRoom = rooms[0];
    // Set up player inventory
    Item inventory[10];
    int inventoryCount = 0;
    // Set up input buffer
    char input[50];
    // Game loop
    while (true) {
        // Print room description
        printDescription(currentRoom.description);
        // Check for item in room and add to inventory if found
        if (strlen(currentRoom.item.name) > 0) {
            printf("\nYou see a %s.\n", currentRoom.item.name);
            printf("Do you want to pick it up? (y/n) ");
            fgets(input, 50, stdin);
            if (strcmp(input, "y\n") == 0) {
                printf("\nYou picked up the %s.\n", currentRoom.item.name);
                inventory[inventoryCount] = currentRoom.item;
                inventoryCount++;
                currentRoom.item = (Item) {"", NULL};
            }
        }
        // Print exits
        printExit(currentRoom);
        // Print inventory
        if (inventoryCount > 0) {
            printf("\nYou have the following items:\n");
            for (int i = 0; i < inventoryCount; i++) {
                printInventory(inventory[i]);
            }
        }
        // Check for win
        if (checkWin(currentRoom.item)) {
            currentRoom = rooms[3];
            continue;
        }
        // Get user input for next move
        printf("\nWhat do you want to do? ");
        fgets(input, 50, stdin);
        // Move north
        if (strcmp(input, "n\n") == 0 && currentRoom.north >= 0) {
            currentRoom = rooms[currentRoom.north];
        }
        // Move south
        else if (strcmp(input, "s\n") == 0 && currentRoom.south >= 0) {
            currentRoom = rooms[currentRoom.south];
        }
        // Move east
        else if (strcmp(input, "e\n") == 0 && currentRoom.east >= 0) {
            currentRoom = rooms[currentRoom.east];
        }
        // Move west
        else if (strcmp(input, "w\n") == 0 && currentRoom.west >= 0) {
            currentRoom = rooms[currentRoom.west];
        }
        // Invalid input
        else {
            printf("\nInvalid input. Please try again.\n");
        }
    }
    return 0;
}

// Function to print room description
void printDescription(char *description) {
    printf("\n%s\n", description);
}

// Function to print available exits from room
void printExit(Room room) {
    printf("\nAvailable exits:\n");
    if (room.north >= 0) {
        printf("North\n");
    }
    if (room.south >= 0) {
        printf("South\n");
    }
    if (room.east >= 0) {
        printf("East\n");
    }
    if (room.west >= 0) {
        printf("West\n");
    }
}

// Function to print inventory item
void printInventory(Item item) {
    printf("- %s\n", item.name);
}

// Function to check if win condition is met
bool checkWin(Item item) {
    if (strcmp(item.name, "Key") == 0) {
        printf("\nYou found the key!\n");
        return true;
    }
    return false;
}