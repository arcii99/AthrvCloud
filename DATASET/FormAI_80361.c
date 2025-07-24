//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 20
#define MAX_ITEMS 10

// Inventory item struct
typedef struct {
    char name[MAX_INPUT];
    char description[MAX_INPUT];
} item_t;

// Room struct
typedef struct {
    char name[MAX_INPUT];
    char description[MAX_INPUT];
    item_t items[MAX_ITEMS];
    int item_count;
    int north;
    int south;
    int east;
    int west;
} room_t;

int main() {

    // Create rooms
    room_t room1 = {"Entrance", "You are standing at the entrance.", {}, 0, 0, 0, 0, 2};
    room_t room2 = {"Hallway", "You are standing in the hallway.", {}, 0, 1, 3, 4, 0};
    room_t room3 = {"Library", "You are standing in the library.", {{"book", "A really old book."}}, 1, 0, 0, 0, 1};
    room_t room4 = {"Kitchen", "You are standing in the kitchen.", {{"knife", "A sharp knife."}}, 1, 2, 0, 5, 0};
    room_t room5 = {"Dining Room", "You are standing in the dining room.", {}, 0, 0, 0, 0, 4};
    room_t room6 = {"Storage Room", "You are standing in the storage room.", {}, 0, 0, 4, 0, 0};

    // Create array of rooms
    room_t rooms[] = {room1, room2, room3, room4, room5, room6};

    // Set starting room
    int current_room = 0;

    // Main game loop
    while (1) {
        // Print current room name and description
        printf("\n---%s---\n%s\n", rooms[current_room].name, rooms[current_room].description);

        // Print items in room
        if (rooms[current_room].item_count > 0) {
            printf("You see:\n");
            for (int i = 0; i < rooms[current_room].item_count; i++) {
                printf("- %s (%s)\n", rooms[current_room].items[i].name, rooms[current_room].items[i].description);
            }
        }

        // Get user input
        char input[MAX_INPUT];
        printf("\nWhat do you want to do? ");
        fgets(input, MAX_INPUT, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse user input
        if (strcmp(input, "quit") == 0) {
            // Quit game
            printf("Game over. Thanks for playing!\n");
            break;
        } else if (strcmp(input, "north") == 0) {
            // Move north if possible
            if (rooms[current_room].north != 0) {
                printf("You move to the north.\n");
                current_room = rooms[current_room].north;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            // Move south if possible
            if (rooms[current_room].south != 0) {
                printf("You move to the south.\n");
                current_room = rooms[current_room].south;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            // Move east if possible
            if (rooms[current_room].east != 0) {
                printf("You move to the east.\n");
                current_room = rooms[current_room].east;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            // Move west if possible
            if (rooms[current_room].west != 0) {
                printf("You move to the west.\n");
                current_room = rooms[current_room].west;
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "look") == 0) {
            // Re-print current room description
            printf("%s\n", rooms[current_room].description);
        } else if (strncmp(input, "get ", 4) == 0) {
            // Get item from room
            char item_name[MAX_INPUT];
            strncpy(item_name, input+4, MAX_INPUT);
            for (int i = 0; i < rooms[current_room].item_count; i++) {
                if (strcmp(rooms[current_room].items[i].name, item_name) == 0) {
                    printf("You pick up the %s.\n", item_name);
                    // Add item to inventory
                    // TODO: Implement inventory functionality
                    // Remove item from room
                    rooms[current_room].item_count--;
                    for (int j = i; j < rooms[current_room].item_count; j++) {
                        rooms[current_room].items[j] = rooms[current_room].items[j+1];
                    }
                    break;
                }
            }
        } else {
            printf("I don't understand what you mean.\n");
        }
    }

    return 0;
}