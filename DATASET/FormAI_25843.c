//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold room information
typedef struct Room {
    char name[50];
    char description[200];
    int north;
    int south;
    int east;
    int west;
} Room;

int main() {
    // Creating array of rooms
    Room rooms[5];
    
    // Setting up rooms
    strcpy(rooms[0].name, "Starting Room");
    strcpy(rooms[0].description, "This is the starting room, you see a door to the north and a door to the east.");
    rooms[0].north = 3;
    rooms[0].east = 1;
    
    strcpy(rooms[1].name, "Hallway");
    strcpy(rooms[1].description, "You are in a dimly lit hallway, there is a door to the west and a door to the south");
    rooms[1].west = 0;
    rooms[1].south = 2;
    
    strcpy(rooms[2].name, "Bedroom");
    strcpy(rooms[2].description, "You are in a small bedroom, there is a door to the north.");
    rooms[2].north = 1;
    
    strcpy(rooms[3].name, "Storeroom");
    strcpy(rooms[3].description, "You are in a cluttered storeroom, there is a door to the south.");
    rooms[3].south = 0;
    
    // Setting up player
    int current_room = 0;
    printf("You wake up in a room, you look around and see nothing but darkness.\n");
    
    // Main game loop
    while (1) {
        // Printing room information
        printf("\n\nYou are in %s\n", rooms[current_room].name);
        printf("%s\n", rooms[current_room].description);
        
        // Getting user input
        char input[10];
        printf("\nWhere do you want to go? (north, south, east, west) ");
        fgets(input, sizeof(input), stdin);
        
        // Removing newline character from input
        input[strcspn(input, "\n")] = 0;
        
        // Moving player based on input
        if (strcmp(input, "north") == 0) {
            if (rooms[current_room].north != -1) {
                current_room = rooms[current_room].north;
            } else {
                printf("There is no door to the north.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (rooms[current_room].south != -1) {
                current_room = rooms[current_room].south;
            } else {
                printf("There is no door to the south.\n");
            }
        } else if (strcmp(input, "east") == 0) {
            if (rooms[current_room].east != -1) {
                current_room = rooms[current_room].east;
            } else {
                printf("There is no door to the east.\n");
            }
        } else if (strcmp(input, "west") == 0) {
            if (rooms[current_room].west != -1) {
                current_room = rooms[current_room].west;
            } else {
                printf("There is no door to the west.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    
    return 0;
}