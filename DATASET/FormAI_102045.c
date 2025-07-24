//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    char* name;
    char* description;
    int north;
    int south;
    int east;
    int west;
} Room;

Room kitchen = {"Kitchen", "You are in a large kitchen with a stove and refrigerator.", -1, 1, -1, 3};
Room living_room = {"Living Room", "You are in a spacious living room with a couch and TV.", -1, 2, 0, 4};
Room hallway = {"Hallway", "You are in a narrow hallway with doors on each side.", 0, 3, 1, 5};
Room bedroom = {"Bedroom", "You are in a cozy bedroom with a bed and dresser.", 2, -1, 4, -1};
Room bathroom = {"Bathroom", "You are in a clean bathroom with a sink, toilet, and shower.", -1, 4, 3, -1};
Room outside = {"Outside", "You step outside and breathe in the fresh air.", 5, -1, -1, -1};

// Function to print current room information
void print_room(Room current_room) {
    printf("\nYou are now in the %s.\n", current_room.name);
    printf("%s\n", current_room.description);
}

int main() {
    Room current_room = kitchen;
    char input[20];

    printf("Welcome to Text Adventure!\n");

    while (1) {
        print_room(current_room);

        // Prompt user for input
        printf("Where would you like to go? (north, south, east, west)\n");
        fgets(input, 20, stdin);

        // Check if input matches valid directions
        if (strcmp(input, "north\n") == 0 && current_room.north != -1) {
            switch (current_room.north) {
                case 0:
                    current_room = hallway;
                    break;
                case 2:
                    current_room = bedroom;
                    break;
                case 5:
                    current_room = outside;
                    printf("\nCongratulations, you have escaped the house and won the game!\n");
                    exit(0);
            }
        } else if (strcmp(input, "south\n") == 0 && current_room.south != -1) {
            switch (current_room.south) {
                case 1:
                    current_room = living_room;
                    break;
                case 3:
                    current_room = bathroom;
                    break;
            }
        } else if (strcmp(input, "east\n") == 0 && current_room.east != -1) {
            switch (current_room.east) {
                case 0:
                    current_room = hallway;
                    break;
                case 3:
                    current_room = bathroom;
                    break;
                case 4:
                    current_room = outside;
                    printf("\nCongratulations, you have escaped the house and won the game!\n");
                    exit(0);
            }
        } else if (strcmp(input, "west\n") == 0 && current_room.west != -1) {
            switch (current_room.west) {
                case 1:
                    current_room = kitchen;
                    break;
                case 5:
                    current_room = hallway;
                    break;
            }
        } else {
            printf("\nInvalid direction. Please try again.\n");
        }
    }

    return 0;
}