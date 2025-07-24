//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 3
#define MAX_REQ_ITEMS 2
#define MAX_INPUT_LENGTH 50

// Struct for an Item
typedef struct Item {
    char name[MAX_INPUT_LENGTH];
    int is_required;
    int is_found;
} Item;

// Struct for a Room
typedef struct Room {
    char description[MAX_INPUT_LENGTH];
    struct Room *north;
    struct Room *south;
    struct Room *east;
    struct Room *west;
    Item items[MAX_ITEMS];
    Item required_items[MAX_REQ_ITEMS];
} Room;

// Function to randomly generate Items for a Room
void randomize_items(Room *room) {
    int i, required_items_count = 0;
    char item_names[MAX_ITEMS][MAX_INPUT_LENGTH] = {"key", "map", "torch", "book", "pen", "hat"};
    for (i=0; i<MAX_ITEMS; i++) {
        strcpy(room->items[i].name, item_names[rand()%MAX_ITEMS]);
        room->items[i].is_found = 0;
        if (rand()%2 == 0 && required_items_count < MAX_REQ_ITEMS) {
            room->items[i].is_required = 1;
            strcpy(room->required_items[required_items_count].name, room->items[i].name);
            room->required_items[required_items_count].is_found = 0;
            required_items_count++;
        }
        else {
            room->items[i].is_required = 0;
        }
    }
}

// Function to randomly generate Rooms and connect them
void connect_rooms(Room *rooms[]) {
    int i, j, direction;
    for (i=0; i<MAX_ROOMS; i++) {
        rooms[i] = malloc(sizeof(Room));
        sprintf(rooms[i]->description, "This is Room %d", i+1);
        randomize_items(rooms[i]);
        rooms[i]->north = NULL;
        rooms[i]->south = NULL;
        rooms[i]->east = NULL;
        rooms[i]->west = NULL;
    }
    for (i=0; i<MAX_ROOMS; i++) {
        j = rand()%MAX_ROOMS;
        while (rooms[j] == rooms[i]) {
            j = rand()%MAX_ROOMS;
        }
        direction = rand()%4;
        switch(direction) {
            case 0:
                rooms[i]->north = rooms[j];
                rooms[j]->south = rooms[i];
                break;
            case 1:
                rooms[i]->south = rooms[j];
                rooms[j]->north = rooms[i];
                break;
            case 2:
                rooms[i]->east = rooms[j];
                rooms[j]->west = rooms[i];
                break;
            case 3:
                rooms[i]->west = rooms[j];
                rooms[j]->east = rooms[i];
                break;
            default:
                break;
        }
    }
}

// Function to print the items in a Room
void print_items(Room *room) {
    int i;
    printf("In this room:");
    for (i=0; i<MAX_ITEMS; i++) {
        if (strlen(room->items[i].name) > 0) {
            printf("\n- %s", room->items[i].name);
        }
    }
    printf("\n");
}

// Function to print the required items in a Room
void print_required_items(Room *room) {
    int i;
    printf("Required items in this room:");
    for (i=0; i<MAX_REQ_ITEMS; i++) {
        if (strlen(room->required_items[i].name) > 0) {
            printf("\n- %s", room->required_items[i].name);
        }
    }
    printf("\n");
}

// Function to check if all the required items in a Room have been found
int check_required_items(Room *room) {
    int i, count=0;
    for (i=0; i<MAX_REQ_ITEMS; i++) {
        if (room->required_items[i].is_required && room->required_items[i].is_found) {
            count++;
        }
    }
    return count == MAX_REQ_ITEMS;
}

// Main function that starts the game
int main() {
    srand(time(NULL));
    Room *rooms[MAX_ROOMS];
    connect_rooms(rooms);

    Room *current_room = rooms[0];
    char input[MAX_INPUT_LENGTH];
    int i, found_items_count = 0;

    printf("Welcome to the Adventure Game!\n\n");
    printf("You find yourself in a strange place and you have to find a way out.\n\n");

    // Main game loop
    while (1) {
        // Print description of current room
        printf("%s\n", current_room->description);

        // Check if there are any items in the room
        print_items(current_room);

        // Check if there are any required items in the room
        print_required_items(current_room);

        // Get user input
        printf("\nEnter a direction (North, South, East, or West) or a command (Pick up, Put down, or Quit):\n");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strlen(input)-1] = '\0';

        // Move to a different room
        if (strcmp(input, "North") == 0 && current_room->north != NULL) {
            current_room = current_room->north;
        }
        else if (strcmp(input, "South") == 0 && current_room->south != NULL) {
            current_room = current_room->south;
        }
        else if (strcmp(input, "East") == 0 && current_room->east != NULL) {
            current_room = current_room->east;
        }
        else if (strcmp(input, "West") == 0 && current_room->west != NULL) {
            current_room = current_room->west;
        }

        // Pick up an item
        else if (strcmp(input, "Pick up") == 0) {
            printf("What item do you want to pick up?\n");
            fgets(input, MAX_INPUT_LENGTH, stdin);
            input[strlen(input)-1] = '\0';
            for (i=0; i<MAX_ITEMS; i++) {
                if (strcmp(current_room->items[i].name, input) == 0) {
                    printf("You picked up a %s.\n", input);
                    current_room->items[i].is_found = 1;
                    found_items_count++;
                    break;
                }
            }
            if (check_required_items(current_room)) {
                printf("You have found all the required items in this room.\n");
            }
        }

        // Put down an item
        else if (strcmp(input, "Put down") == 0) {
            printf("What item do you want to put down?\n");
            fgets(input, MAX_INPUT_LENGTH, stdin);
            input[strlen(input)-1] = '\0';
            for (i=0; i<MAX_ITEMS; i++) {
                if (strcmp(current_room->items[i].name, input) == 0 && current_room->items[i].is_found) {
                    printf("You put down a %s.\n", input);
                    current_room->items[i].is_found = 0;
                    found_items_count--;
                    break;
                }
            }
        }

        // Quit the game
        else if (strcmp(input, "Quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        // Invalid input
        else {
            printf("Invalid input. Please try again.\n");
        }

        // Check if all required items have been found and the player has left the last room
        if (found_items_count == MAX_REQ_ITEMS && current_room == rooms[MAX_ROOMS-1]) {
            printf("You have found all the required items and escaped the game!\n");
            break;
        }
    }

    // Free dynamically allocated memory
    for (i=0; i<MAX_ROOMS; i++) {
        free(rooms[i]);
    }

    return 0;
}