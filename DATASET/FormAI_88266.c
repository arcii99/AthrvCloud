//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

struct Room {
    char name[20];
    char description[100];
    int north;
    int east;
    int south;
    int west;
};

struct Room rooms[5];

void initRooms() {
    strcpy(rooms[0].name, "Entrance");
    strcpy(rooms[0].description, "You are standing at the entrance of an old abandoned mansion.");
    rooms[0].north = 1;
    rooms[0].east = -1;
    rooms[0].south = -1;
    rooms[0].west = -1;

    strcpy(rooms[1].name, "Foyer");
    strcpy(rooms[1].description, "You have entered the foyer.");
    rooms[1].north = -1;
    rooms[1].east = 3;
    rooms[1].south = 0;
    rooms[1].west = 2;

    strcpy(rooms[2].name, "Study");
    strcpy(rooms[2].description, "You have entered the study.");
    rooms[2].north = -1;
    rooms[2].east = 1;
    rooms[2].south = -1;
    rooms[2].west = -1;

    strcpy(rooms[3].name, "Kitchen");
    strcpy(rooms[3].description, "You have entered the kitchen.");
    rooms[3].north = 4;
    rooms[3].east = -1;
    rooms[3].south = -1;
    rooms[3].west = 1;

    strcpy(rooms[4].name, "Pantry");
    strcpy(rooms[4].description, "You have entered the pantry.");
    rooms[4].north = -1;
    rooms[4].east = -1;
    rooms[4].south = 3;
    rooms[4].west = -1;
}

int main() {
    initRooms();
    int currentRoom = 0;
    char input[MAX_INPUT_LENGTH];
    int endGame = 0;
    srand(time(NULL));

    printf("Welcome to the Mansion Adventure Game!\n");
    while (!endGame) {
        // Print room description
        printf("%s\n", rooms[currentRoom].description);

        // Randomly add a clue
        int clue = rand() % 10;
        if (clue == 5) {
            printf("You notice a piece of paper on the ground.\n");
            printf("You pick it up and it says, 'The key is hidden in the kitchen.'\n");
        }

        printf("What would you like to do next? ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        // Convert input to lowercase for easy comparison
        for (int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            endGame = 1;
        } else if (strcmp(input, "look") == 0) {
            // Print room description again
            printf("%s\n", rooms[currentRoom].description);
        } else if (strcmp(input, "north") == 0 && rooms[currentRoom].north != -1) {
            currentRoom = rooms[currentRoom].north;
        } else if (strcmp(input, "east") == 0 && rooms[currentRoom].east != -1) {
            currentRoom = rooms[currentRoom].east;
        } else if (strcmp(input, "south") == 0 && rooms[currentRoom].south != -1) {
            currentRoom = rooms[currentRoom].south;
        } else if (strcmp(input, "west") == 0 && rooms[currentRoom].west != -1) {
            currentRoom = rooms[currentRoom].west;
        } else {
            printf("Sorry, I don't understand.\n");
        }
    }

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}