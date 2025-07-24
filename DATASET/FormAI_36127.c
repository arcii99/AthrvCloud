//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//constants
#define NUM_ROOMS 6
#define MAX_NAME_SIZE 15

//room struct definition
typedef struct {
    char name[MAX_NAME_SIZE];
    int isHaunted;
} Room;

//function prototypes
void createRooms(Room rooms[]);
void checkForGhost(Room rooms[]);
void printGameMessage(int restlessGhosts, char* currentRoomName);
void waitForEnter();
int getRandomIndex();

int main() {
    //seed random number generator
    srand(time(0));
    
    //create array of rooms
    Room rooms[NUM_ROOMS];
    createRooms(rooms);
    
    //initialize game variables
    int restlessGhosts = 3;
    int currentRoomIndex = 0;
    char* currentRoomName = rooms[currentRoomIndex].name;
    
    //game loop
    while(restlessGhosts > 0) {
        printGameMessage(restlessGhosts, currentRoomName);
        waitForEnter();
        checkForGhost(rooms);
        currentRoomIndex = getRandomIndex();
        currentRoomName = rooms[currentRoomIndex].name;
    }
    
    //game over message
    printf("\nYou have vanquished all the restless ghosts!\n");
    return 0;
}

//function to create initial rooms
void createRooms(Room rooms[]) {
    strcpy(rooms[0].name, "Foyer");
    rooms[0].isHaunted = 1;
    strcpy(rooms[1].name, "Kitchen");
    rooms[1].isHaunted = 0;
    strcpy(rooms[2].name, "Living Room");
    rooms[2].isHaunted = 1;
    strcpy(rooms[3].name, "Dining Room");
    rooms[3].isHaunted = 0;
    strcpy(rooms[4].name, "Bedroom");
    rooms[4].isHaunted = 1;
    strcpy(rooms[5].name, "Bathroom");
    rooms[5].isHaunted = 0;
}

//function to check if current room has a ghost
void checkForGhost(Room rooms[]) {
    int currentRoomIndex = getRandomIndex();
    if(rooms[currentRoomIndex].isHaunted) {
        printf("\nYou have encountered a restless ghost in the %s! Better run to another room...\n\n", rooms[currentRoomIndex].name);
    } else {
        printf("\nPhew, no ghosts here! Let's move onto another room...\n\n");
    }
}

//function to print game message
void printGameMessage(int restlessGhosts, char* currentRoomName) {
    printf("\nYou are currently in the %s. There are still %d restless ghosts haunting the house. Press enter to move to another room.\n", currentRoomName, restlessGhosts);
}

//function to wait for enter key before continuing game
void waitForEnter() {
    printf("Press enter to continue...");
    while(getchar() != '\n');
}

//function to generate random room index
int getRandomIndex() {
    return rand() % NUM_ROOMS;
}