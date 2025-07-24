//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 3 

// Room struct 
typedef struct Room {
    int id;
    int isHaunted;
    int connectedRooms[MAX_ROOMS];
} Room;

// Ghost struct 
typedef struct Ghost {
    int id;
    int room;
} Ghost;

// Function declarations 
void printWelcomeMessage();
void setupRooms(Room *rooms, int numRooms);
void setupGhost(Ghost *ghost, Room *rooms, int numRooms);
void printMap(Room *rooms, int numRooms);
int getNextRoom(Room room);
void hauntRoom(Room *room, Ghost *ghost);
void unleashGhosts(Room *rooms, Ghost *ghosts, int numRooms, int numGhosts);

// Main function 
int main() {
    // initialize randomizer 
    srand(time(NULL));
    
    // define variables 
    Room rooms[MAX_ROOMS];
    Ghost ghosts[MAX_GHOSTS];
    int numRooms = MAX_ROOMS;
    int numGhosts = MAX_GHOSTS;
    
    // print welcome message 
    printWelcomeMessage();
    
    // setup rooms and ghosts 
    setupRooms(rooms, numRooms);
    setupGhost(ghosts, rooms, numRooms);
    
    // print map of the house 
    printMap(rooms, numRooms);
    
    // unleash the ghosts! 
    unleashGhosts(rooms, ghosts, numRooms, numGhosts);
    
    return 0;
}

// Prints out a welcome message 
void printWelcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house with %d rooms and %d ghosts.\n", MAX_ROOMS, MAX_GHOSTS);
    printf("Your goal is to find your way out without getting caught by the ghosts.\n");
    printf("Good luck!\n\n");
}

// Sets up the rooms 
void setupRooms(Room *rooms, int numRooms) {
    // initialize rooms 
    for(int i = 0; i < numRooms; i++) {
        rooms[i].id = i+1;
        rooms[i].isHaunted = rand() % 2; // randomly set if room is haunted or not 
        
        // randomly connect rooms 
        for(int j = 0; j < MAX_ROOMS; j++) {
            rooms[i].connectedRooms[j] = 0; // initialize array to 0 
            
            if(i != j && rand() % 2 == 1) {
                rooms[i].connectedRooms[j] = 1;
            }
        }
    }
}

// Sets up the ghosts 
void setupGhost(Ghost *ghosts, Room *rooms, int numRooms) {
    // initialize ghosts 
    for(int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].id = i+1;
        ghosts[i].room = rand() % MAX_ROOMS + 1; // randomly place ghosts in a room 
        rooms[ghosts[i].room - 1].isHaunted = 1; // mark room as haunted 
    }
}

// Prints out a map of the house 
void printMap(Room *rooms, int numRooms) {
    printf("MAP OF THE HAUNTED HOUSE\n");
    printf("------------------------\n");
    
    for(int i = 0; i < numRooms; i++) {
        printf("ROOM %d: ", rooms[i].id);
        if(rooms[i].isHaunted) {
            printf("HAUNTED ");
        } else {
            printf("        ");
        }
        
        printf("CONNECTS TO: ");
        for(int j = 0; j < MAX_ROOMS; j++) {
            if(rooms[i].connectedRooms[j]) {
                printf("%d ", j+1);
            }
        }
        
        printf("\n");
    }
    
    printf("\n");
}

// Gets the next room to move to 
int getNextRoom(Room room) {
    int connectedRooms[MAX_ROOMS];
    int numConnectedRooms = 0;
    
    // find all connected rooms 
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(room.connectedRooms[i]) {
            connectedRooms[numConnectedRooms] = i+1;
            numConnectedRooms++;
        }
    }
    
    // return a random connected room 
    return connectedRooms[rand() % numConnectedRooms];
}

// Haunts a room with a ghost 
void hauntRoom(Room *room, Ghost *ghost) {
    if(room->isHaunted) {
        printf("You have been caught by Ghost %d in Room %d!\nGAME OVER\n", ghost->id, room->id);
        exit(0);
    } else {
        printf("You have entered Room %d safely.\n", room->id);
    }
}

// Unleashes the ghosts into the house 
void unleashGhosts(Room *rooms, Ghost *ghosts, int numRooms, int numGhosts) {
    printf("You are now inside the house. Begin searching for an exit...\n");
    Room currentRoom = rooms[rand() % numRooms]; // start in a random room 
    
    while(1) {
        hauntRoom(&currentRoom, &ghosts[rand() % numGhosts]); // check if room is haunted 
        
        // move to next room 
        int nextRoom = getNextRoom(currentRoom);
        currentRoom = rooms[nextRoom-1];
        
        if(nextRoom == currentRoom.id) { // if no more connected rooms, exit found 
            printf("Congratulations! You have found the exit and escaped the haunted house!\n");
            break;
        }
    }
}