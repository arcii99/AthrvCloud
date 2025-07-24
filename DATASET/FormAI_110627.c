//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROOM_NAME_LENGTH 30
#define ITEM_NAME_LENGTH 20

// Structure representing a game room
typedef struct {
    char name[ROOM_NAME_LENGTH];
    char description[200];
    bool visited;
} Room;

// Structure representing an item in the game
typedef struct {
    char name[ITEM_NAME_LENGTH];
    char description[200];
    bool is_picked_up;
} Item;

// The array of rooms in the game
Room rooms[4] = {
    {"Kitchen", "A room with a stove and fridge.", false},
    {"Bedroom", "A cozy bedroom with a bed and wardrobe.", false},
    {"Bathroom", "A bathroom with a sink, shower and toilet.", false},
    {"Living Room", "A spacious living room with a couch, TV and bookshelf.", false}
};

// The array of items in the game
Item items[4] = {
    {"Knife", "A sharp kitchen knife.", false},
    {"Flashlight", "A small flashlight.", false},
    {"Toothbrush", "A toothbrush with toothpaste.", false},
    {"Book", "A mystery novel.", false}
};

// Prints the introduction text and instructions for the game
void print_intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will explore different rooms and try to find all the items.\n");
    printf("You can move from room to room by typing 'go [room name]'.\n");
    printf("You can pick up an item by typing 'take [item name]'.\n");
    printf("You can check your inventory by typing 'inventory'.\n");
    printf("Good luck and have fun!\n\n");
}

// Prints the description of the given room
void print_room_description(Room room) {
    printf("You are now in the %s.\n", room.name);
    printf("%s\n", room.description);
}

// Returns true if the given item is in the player's inventory; false otherwise
bool is_item_in_inventory(char* item_name, Item* inventory, int inventory_size) {
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, item_name) == 0 && inventory[i].is_picked_up) {
            return true;
        }
    }
    return false;
}

// The main game loop
void play_game() {
    // Set the initial room and player inventory
    Room current_room = rooms[0];
    Item player_inventory[4] = {0};
    int inventory_size = 0;

    // Game loop flag
    bool game_running = true;

    while (game_running) {
        // Print the current room description if the room has not been visited before
        if (!current_room.visited) {
            current_room.visited = true;
            print_room_description(current_room);
        }

        // Read the player's command
        printf("> ");
        char input[100];
        fgets(input, 100, stdin);

        // Tokenize the command input into separate words
        char* command = strtok(input, " \n");
        char* target = strtok(NULL, " \n");

        if (command != NULL) {
            // The player wants to go to another room
            if (strcmp(command, "go") == 0 && target != NULL) {
                // Find the room with the given name
                for (int i = 0; i < 4; i++) {
                    if (strcmp(rooms[i].name, target) == 0) {
                        current_room = rooms[i];
                        break;
                    }
                }
            }

            // The player wants to pick up an item
            else if (strcmp(command, "take") == 0 && target != NULL) {
                // Find the item with the given name
                for (int i = 0; i < 4; i++) {
                    if (strcmp(items[i].name, target) == 0 && !items[i].is_picked_up) {
                        // Add the item to the player's inventory
                        items[i].is_picked_up = true;
                        player_inventory[inventory_size] = items[i];
                        inventory_size++;
                        printf("You picked up the %s.\n", items[i].name);
                        break;
                    }
                }
            }

            // The player wants to check their inventory
            else if (strcmp(command, "inventory") == 0) {
                printf("Your inventory:\n");
                if (inventory_size == 0) {
                    printf("Empty\n");
                } else {
                    for (int i = 0; i < inventory_size; i++) {
                        printf("%s\n", player_inventory[i].name);
                    }
                }
            }

            // The player wants to quit the game
            else if (strcmp(command, "quit") == 0) {
                game_running = false;
            }

            // The player entered an invalid command
            else {
                printf("Invalid command\n");
            }
        }
    }

    printf("Thanks for playing the Text-Based Adventure Game!\n");
}

// The main function
int main() {
    print_intro();
    play_game();
    return 0;
}