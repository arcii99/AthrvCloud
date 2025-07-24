//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Constants for game logic
#define MAX_ITEMS 5
#define MAX_ITEM_NAME_SIZE 25
#define MAX_ROOM_NAME_SIZE 50

// Struct to hold information about the items
typedef struct {
    char name[MAX_ITEM_NAME_SIZE];
    int is_picked_up;
} item_t;

// Struct to hold information about the rooms
typedef struct {
    char name[MAX_ROOM_NAME_SIZE];
    char description[500];
    int details_discovered;
    item_t items[MAX_ITEMS];
} room_t;

// Function to display the introductory message and instructions to the player
void display_intro_message() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are now trapped in a mysterious house and your goal is to escape it.\n");
    printf("You will navigate through various rooms, each with unique items and secrets.\n");
    printf("You can type 'inventory' to display your current inventory and 'quit' to exit the game.\n");
    printf("Good luck!\n\n");
}

// Function to display the current room details
void display_room_details(room_t room) {
    printf("%s\n\n", room.name);
    printf("%s\n", room.description);
    printf("This room contains:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (room.items[i].is_picked_up == 0) {
            printf("- %s\n", room.items[i].name);
        }
    }
    printf("\n");
}

// Function to handle player movement between rooms
void move_player(room_t *current_room, room_t rooms[], int num_rooms) {
    char input[10];
    printf("Enter the name of the room you want to move to: ");
    scanf("%s", input);
    printf("\n");
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(input, rooms[i].name) == 0) {
            *current_room = rooms[i];
            return;
        }
    }
    printf("Invalid input, try again.\n\n");
}

// Function to handle item pickup and addition to player's inventory
void pickup_item(room_t *current_room, item_t *inventory) {
    char input[50];
    printf("Enter the name of the item you want to pick up: ");
    scanf("%s", input);
    printf("\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(input, current_room->items[i].name) == 0) {
            if (current_room->items[i].is_picked_up == 0) {
                for (int j = 0; j < MAX_ITEMS; j++) {
                    if (strlen(inventory[j].name) == 0) {
                        strcpy(inventory[j].name, current_room->items[i].name);
                        current_room->items[i].is_picked_up = 1;
                        printf("You have picked up %s.\n\n", inventory[j].name);
                        return;
                    }
                }
                printf("Inventory is full, cannot pick up any more items.\n\n");
                return;
            }
            printf("Item already picked up.\n\n");
            return;
        }
    }
    printf("Invalid input, try again.\n\n");
}

// Function to handle player inventory view
void view_inventory(item_t inventory[]) {
    printf("Your inventory contains:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(inventory[i].name) > 0) {
            printf("- %s\n", inventory[i].name);
        }
    }
    printf("\n");
}

// Function to play the game
void play_game() {
    int num_of_rooms = 3;
    room_t rooms[num_of_rooms];
    strcpy(rooms[0].name, "Living Room");
    strcpy(rooms[0].description, "This room contains a couch, a TV, and a fireplace.");
    rooms[0].details_discovered = 0;
    strcpy(rooms[0].items[0].name, "Key");
    rooms[0].items[0].is_picked_up = 0;
    rooms[0].items[1].is_picked_up = 1;
    strcpy(rooms[1].name, "Kitchen");
    strcpy(rooms[1].description, "This room contains a table, a fridge, and a stove.");
    rooms[1].details_discovered = 0;
    strcpy(rooms[1].items[0].name, "Knife");
    rooms[1].items[0].is_picked_up = 0;
    rooms[1].items[1].is_picked_up = 1;
    strcpy(rooms[2].name, "Bedroom");
    strcpy(rooms[2].description, "This room contains a bed, a dresser, and a closet.");
    rooms[2].details_discovered = 0;
    strcpy(rooms[2].items[0].name, "Flashlight");
    rooms[2].items[0].is_picked_up = 0;
    rooms[2].items[1].is_picked_up = 1;
    item_t inventory[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++) {
        inventory[i].is_picked_up = 0;
    }
    room_t current_room = rooms[0];
    int game_over = 0;
    display_intro_message();
    while (!game_over) {
        display_room_details(current_room);
        char input[10];
        printf("What do you want to do? ");
        scanf("%s", input);
        printf("\n");
        if (strcmp(input, "move") == 0) {
            move_player(&current_room, rooms, num_of_rooms);
        }
        else if (strcmp(input, "pickup") == 0) {
            pickup_item(&current_room, inventory);
        }
        else if (strcmp(input, "inventory") == 0) {
            view_inventory(inventory);
        }
        else if (strcmp(input, "quit") == 0) {
            game_over = 1;
            printf("Thanks for playing!\n");
        }
        else {
            printf("Invalid input, try again.\n\n");
        }
    }
}

int main() {
    play_game();
    return 0;
}