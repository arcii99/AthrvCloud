//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

// Room struct to represent each location in the game world
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
} Room;

// Function to create a new Room struct and return a pointer to it
Room* create_room(char* name, char* description) {
    Room* new_room = malloc(sizeof(Room));
    new_room->name = name;
    new_room->description = description;
    new_room->north = NULL;
    new_room->south = NULL;
    new_room->east = NULL;
    new_room->west = NULL;
    return new_room;
}

// Populate the game world with rooms and connect them using pointers
void populate_game_world(Room** player_location) {
    // Create all the rooms in the game world
    Room* start_room = create_room("Start Room", "You are in a small room with a door to the north.");
    Room* north_room = create_room("North Room", "You are in a large, empty room with a door to the south.");
    Room* south_room = create_room("South Room", "You are in a dark, damp room with a door to the north and a door to the east.");
    Room* east_room = create_room("East Room", "You are in a room with a strange artifact on a pedestal. There is a door to the west.");
    Room* artifact_room = create_room("Artifact Room", "You have retrieved the artifact! There is a door to the west.");

    // Connect the rooms using pointers
    start_room->north = north_room;
    north_room->south = start_room;
    north_room->north = south_room;
    south_room->south = north_room;
    south_room->east = artifact_room;
    artifact_room->west = south_room;
    east_room->west = artifact_room;
    artifact_room->east = east_room;

    // Set the player's initial location to the start room
    *player_location = start_room;
}

// Print the player's current location and description
void print_location(Room* player_location) {
    printf("\n%s\n\n%s\n\n", player_location->name, player_location->description);
}

// Process the player's input and take the appropriate action
void process_input(Room** player_location, char* input) {
    // Remove leading and trailing whitespace from the input
    int length = strlen(input);
    while (isspace(input[length-1])) {
        input[--length] = 0;
    }
    while (*input && isspace(*input)) {
        ++input, --length;
    }

    // Convert input to lowercase
    for (int i = 0; i < length; i++) {
        input[i] = tolower(input[i]);
    }

    // Check what action to take based on the input
    if (strcmp(input, "north") == 0) {
        if ((*player_location)->north != NULL) {
            *player_location = (*player_location)->north;
            print_location(*player_location);
        } else {
            printf("\nYou can't go that way!\n\n");
        }
    } else if (strcmp(input, "south") == 0) {
        if ((*player_location)->south != NULL) {
            *player_location = (*player_location)->south;
            print_location(*player_location);
        } else {
            printf("\nYou can't go that way!\n\n");
        }
    } else if (strcmp(input, "east") == 0) {
        if ((*player_location)->east != NULL) {
            *player_location = (*player_location)->east;
            print_location(*player_location);
        } else {
            printf("\nYou can't go that way!\n\n");
        }
    } else if (strcmp(input, "west") == 0) {
        if ((*player_location)->west != NULL) {
            *player_location = (*player_location)->west;
            print_location(*player_location);
        } else {
            printf("\nYou can't go that way!\n\n");
        }
    } else if (strcmp(input, "take artifact") == 0) {
        if ((*player_location)->east != NULL && (*player_location)->east->east == NULL) {
            (*player_location)->east->east = create_room("", "");
            printf("\nYou have taken the artifact!\n\n");
            print_location(*player_location);
        } else {
            printf("\nThere is nothing to take!\n\n");
        }
    } else if (strcmp(input, "quit") == 0) {
        printf("\nGoodbye!\n\n");
        exit(0);
    } else {
        printf("\nI don't understand that command!\n\n");
    }
}

int main() {
    Room* player_location;
    populate_game_world(&player_location);
    printf("Welcome to the game!\n\n");

    // Game loop
    char input[MAX_INPUT_LENGTH];
    while (true) {
        print_location(player_location);
        printf("Enter a command: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        process_input(&player_location, input);
    }
    
    return 0;
}