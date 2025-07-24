//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
// Welcome to "The Quest for the Golden Amulet"!

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 20
#define MAX_INPUT_LEN 50
#define MAX_ITEMS 5

// Struct to hold information about items.
typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_INPUT_LEN];
} Item;

// Struct to hold information about rooms.
typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_INPUT_LEN];
    Item items[MAX_ITEMS];
    bool visited;
} Room;

// Create the two rooms in the game.
Room starting_room = {
    "Starting Room",
    "You are standing in a small room with a single door.",
    {},
    false
};
Room treasure_room = {
    "Treasure Room",
    "You have entered the treasure room. The golden amulet is within reach!",
    {},
    false
};

// Function to simulate getting an item.
void get_item(Item* item) {
    printf("You acquired %s: %s\n", item->name, item->description);
}

int main() {
    printf("Welcome to \"The Quest for the Golden Amulet\"!\n\n");

    // Add items to the starting room.
    Item key = {
        "Key",
        "A small key that could fit into a lock."
    };
    starting_room.items[0] = key;

    // Set up the player's inventory.
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    // Set up the initial room.
    Room* current_room = &starting_room;
    current_room->visited = true;

    // Main game loop.
    while (true) {
        // Print the current room information.
        printf("%s\n\n", current_room->description);

        // Print the items in the current room.
        int num_items_in_room = 0;
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (strlen(current_room->items[i].name) > 0) {
                printf("You see a %s on the ground.\n", current_room->items[i].name);
                num_items_in_room++;
            }
        }
        if (num_items_in_room == 0) {
            printf("There are no items in this room.\n");
        }
        printf("\n");

        // Get user input.
        char input[MAX_INPUT_LEN];
        printf("> ");
        fgets(input, MAX_INPUT_LEN, stdin);

        // Process user input.
        if (strncmp(input, "exit", MAX_INPUT_LEN) == 0) {
            printf("Thank you for playing \"The Quest for the Golden Amulet\"!\n");
            return 0;
        }
        else if (strncmp(input, "look", MAX_INPUT_LEN) == 0) {
            printf("%s\n\n", current_room->description);
        }
        else if (strncmp(input, "inventory", MAX_INPUT_LEN) == 0) {
            if (num_items == 0) {
                printf("Your inventory is empty.\n\n");
            }
            else {
                printf("Your inventory:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("- %s: %s\n", inventory[i].name, inventory[i].description);
                }
                printf("\n");
            }
        }
        else if (strncmp(input, "get", 3) == 0) {
            char item_name[MAX_INPUT_LEN];
            sscanf(input, "%*s %s", item_name);
            bool item_found = false;
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (strcmp(item_name, current_room->items[i].name) == 0) {
                    get_item(&current_room->items[i]);
                    inventory[num_items++] = current_room->items[i];
                    current_room->items[i].name[0] = '\0';
                    item_found = true;
                    break;
                }
            }
            if (!item_found) {
                printf("There is no %s in this room.\n\n", item_name);
            }
        }
        else if (strncmp(input, "go", 2) == 0) {
            char room_name[MAX_NAME_LEN];
            sscanf(input, "%*s %s", room_name);
            if (strcmp(room_name, "starting") == 0 && current_room != &starting_room) {
                current_room = &starting_room;
                current_room->visited = true;
            }
            else if (strcmp(room_name, "treasure") == 0 && current_room != &treasure_room) {
                current_room = &treasure_room;
                current_room->visited = true;
            }
            else {
                printf("You cannot go there from here.\n\n");
            }
        }
        else {
            printf("I'm sorry, I don't understand what you're trying to do. Please try again.\n\n");
        }

        // Check if the player has won.
        if (current_room == &treasure_room && num_items == 1 && strcmp(inventory[0].name, "Key") == 0) {
            printf("Congratulations! You have found the Golden Amulet and won the game!\n");
            return 0;
        }
    }
}