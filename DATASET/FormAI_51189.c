//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LENGTH 50

// Function to print a room description and options
void print_room(int room_number) {
    printf("You are in room %d.\n", room_number);
    if (room_number == 1) {
        printf("It's cold and dark in here. You can hear faint whispers and creaking of floorboards.\n");
        printf("Exits: North, East\n");
    } else if (room_number == 2) {
        printf("There's a musty smell in here. You can barely see anything in the dim light.\n");
        printf("Exits: North, South, West\n");
    } else if (room_number == 3) {
        printf("You feel a chill run down your spine as you enter. The walls are covered in dried blood.\n");
        printf("Exits: East, West\n");
    } else if (room_number == 4) {
        printf("The room is empty except for a dusty grandfather clock that ticks ominously.\n");
        printf("Exits: South\n");
    } else if (room_number == 5) {
        printf("Cobwebs cover every surface in the room. You can hear something scurrying in the darkness.\n");
        printf("Exits: North, East, West\n");
    } else if (room_number == 6) {
        printf("You've entered a library complete with bookshelves towering high above you.\n");
        printf("Exits: South, West\n");
    } else if (room_number == 7) {
        printf("You find yourself in a kitchen, but all the utensils are rusted and the food has long gone bad.\n");
        printf("Exits: North, South, East\n");
    } else if (room_number == 8) {
        printf("A ghostly apparition appears before you in the dim light, but vanishes quickly. The room is filled with a dense fog.\n");
        printf("Exits: West\n");
    } else if (room_number == 9) {
        printf("The room seems normal at first, but suddenly the walls start closing in on you.\n");
        printf("Exits: East\n");
    } else if (room_number == 10) {
        printf("You can smell burning candles and see movement in the shadows, but no one is there.\n");
        printf("Exits: South, West\n");
    }
}

int main() {
    int current_room = 1;
    char command[MAX_LENGTH];
    srand(time(NULL)); // Initialize random seed

    printf("Welcome to the Haunted House Simulator! Type 'help' for a list of commands.\n");

    // Game loop
    while (1) {
        print_room(current_room);

        // Ask for user input
        printf("\n> ");
        fgets(command, MAX_LENGTH, stdin);

        // Remove trailing newline from input
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "help") == 0) {
            printf("Commands: \n");
            printf("  go <direction>\tMove in a direction (North, South, East, West)\n");
            printf("  look\t\tLook around the room\n");
            printf("  quit\t\tQuit the game\n");
        } else if (strcmp(command, "look") == 0) {
            // Reprint the room description
            print_room(current_room);
        } else if (strcmp(command, "quit") == 0) {
            // End the game loop
            break;
        } else if (strncmp(command, "go ", 3) == 0) {
            // Parse the direction from the command
            char *direction = command + 3;

            // Determine which room to move to based on the current room and chosen direction
            int new_room;
            if (strcmp(direction, "North") == 0 && (current_room == 1 || current_room == 2 || current_room == 5 || current_room == 7)) {
                new_room = current_room + 1;
            } else if (strcmp(direction, "South") == 0 && (current_room == 2 || current_room == 4 || current_room == 7 || current_room == 10)) {
                new_room = current_room - 1;
            } else if (strcmp(direction, "East") == 0 && (current_room == 1 || current_room == 3 || current_room == 5 || current_room == 7 || current_room == 10)) {
                new_room = rand() % MAX_ROOMS + 1;
            } else if (strcmp(direction, "West") == 0 && (current_room == 2 || current_room == 3 || current_room == 6 || current_room == 8 || current_room == 10)) {
                new_room = rand() % MAX_ROOMS + 1;
            } else {
                printf("You can't go that way.\n");
                continue;
            }

            // Update the current room
            current_room = new_room;

            // A chance of something spooky happening
            if (rand() % 2 == 0) {
                printf("You feel a cold breath on your neck.\n");
            }
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}