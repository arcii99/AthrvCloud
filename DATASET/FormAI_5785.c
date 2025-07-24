//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define game parameters
#define MAX_ROOMS 5
#define MAX_ITEMS 3
#define MAX_NAME 20

// Define room structure
struct Room {
    char name[MAX_NAME];
    char description[MAX_NAME];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    struct Item* items[MAX_ITEMS];
};

// Define item structure
struct Item {
    char name[MAX_NAME];
    char description[MAX_NAME];
};

// Function prototypes
void createRooms(struct Room* rooms[]);
void createItems(struct Item* items[]);
void printRoomInfo(struct Room* currentRoom);
void printItemInfo(struct Item* item);
int getInput();
void play();

// Main function
int main() {
    play();
    return 0;
}

// Function to create rooms
void createRooms(struct Room* rooms[]) {
    // Seed random number generator
    srand(time(NULL));
    
    // Create rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = malloc(sizeof(struct Room));
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
        for (int j = 0; j < MAX_ITEMS; j++) {
            rooms[i]->items[j] = NULL;
        }
    }
    
    // Set room names and descriptions
    strcpy(rooms[0]->name, "Living Room");
    strcpy(rooms[0]->description, "A cozy room with a fireplace.");
    
    strcpy(rooms[1]->name, "Kitchen");
    strcpy(rooms[1]->description, "A room with pots and pans hanging from the ceiling.");
    
    strcpy(rooms[2]->name, "Bedroom");
    strcpy(rooms[2]->description, "A peaceful room with a comfortable bed.");
    
    strcpy(rooms[3]->name, "Bathroom");
    strcpy(rooms[3]->description, "A room with a bathtub and a toilet.");
    
    strcpy(rooms[4]->name, "Basement");
    strcpy(rooms[4]->description, "A dark room with old furniture.");
    
    // Set room connections
    int random;
    for (int i = 0; i < MAX_ROOMS; i++) {
        random = rand() % MAX_ROOMS;
        while (random == i) {
            random = rand() % MAX_ROOMS;
        }
        rooms[i]->north = rooms[random];
        
        random = rand() % MAX_ROOMS;
        while (random == i) {
            random = rand() % MAX_ROOMS;
        }
        rooms[i]->south = rooms[random];
        
        random = rand() % MAX_ROOMS;
        while (random == i) {
            random = rand() % MAX_ROOMS;
        }
        rooms[i]->east = rooms[random];
        
        random = rand() % MAX_ROOMS;
        while (random == i) {
            random = rand() % MAX_ROOMS;
        }
        rooms[i]->west = rooms[random];
    }
}

// Function to create items
void createItems(struct Item* items[]) {
    // Create items
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i] = malloc(sizeof(struct Item));
    }
    
    // Set item names and descriptions
    strcpy(items[0]->name, "Key");
    strcpy(items[0]->description, "A small silver key.");
    
    strcpy(items[1]->name, "Note");
    strcpy(items[1]->description, "A piece of paper with a message written on it.");
    
    strcpy(items[2]->name, "Coin");
    strcpy(items[2]->description, "A shiny gold coin.");
}

// Function to print room information
void printRoomInfo(struct Room* currentRoom) {
    printf("You are in the %s.\n", currentRoom->name);
    printf("%s\n", currentRoom->description);
    printf("You see the following items in the room:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (currentRoom->items[i] != NULL) {
            printf("- %s\n", currentRoom->items[i]->name);
        }
    }
    printf("Possible directions to go are:\n");
    if (currentRoom->north != NULL) {
        printf("- North\n");
    }
    if (currentRoom->south != NULL) {
        printf("- South\n");
    }
    if (currentRoom->east != NULL) {
        printf("- East\n");
    }
    if (currentRoom->west != NULL) {
        printf("- West\n");
    }
}

// Function to print item information
void printItemInfo(struct Item* item) {
    printf("You picked up %s.\n", item->name);
    printf("%s\n", item->description);
}

// Function to get input from user
int getInput() {
    printf("\nWhat do you want to do?\n1. Move to direction.\n2. Pick up item.\n3. Quit game.\nEnter number: ");
    int choice;
    scanf("%d", &choice);
    while (choice != 1 && choice != 2 && choice != 3) {
        printf("Invalid input. Enter number: ");
        scanf("%d", &choice);
    }
    return choice;
}

// Function to play the game
void play() {
    printf("Welcome to the minimalist adventure game!\n");
    printf("You find yourself in a strange place.\n");
    printf("Your goal is to find a way out of this place.\n");
    
    // Create rooms and items
    struct Room* rooms[MAX_ROOMS];
    struct Item* items[MAX_ITEMS];
    createRooms(rooms);
    createItems(items);
    
    // Set starting room and add items to rooms
    struct Room* currentRoom = rooms[0];
    currentRoom->items[0] = items[0];
    currentRoom->items[1] = items[1];
    currentRoom->items[2] = items[2];
    
    // Game loop
    int choice;
    while (1) {
        printRoomInfo(currentRoom);
        choice = getInput();
        if (choice == 1) {
            printf("Which direction do you want to go?\n");
            char direction[MAX_NAME];
            scanf("%s", direction);
            if (strcmp(direction, "north") == 0 && currentRoom->north != NULL) {
                currentRoom = currentRoom->north;
            } else if (strcmp(direction, "south") == 0 && currentRoom->south != NULL) {
                currentRoom = currentRoom->south;
            } else if (strcmp(direction, "east") == 0 && currentRoom->east != NULL) {
                currentRoom = currentRoom->east;
            } else if (strcmp(direction, "west") == 0 && currentRoom->west != NULL) {
                currentRoom = currentRoom->west;
            } else {
                printf("You cannot go in that direction.\n");
            }
        } else if (choice == 2) {
            printf("Which item do you want to pick up?\n");
            char itemName[MAX_NAME];
            scanf("%s", itemName);
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (currentRoom->items[i] != NULL && strcmp(itemName, currentRoom->items[i]->name) == 0) {
                    printItemInfo(currentRoom->items[i]);
                    currentRoom->items[i] = NULL;
                    break;
                }
            }
        } else if (choice == 3) {
            printf("Thank you for playing the game! Goodbye!\n");
            break;
        }
    }
}