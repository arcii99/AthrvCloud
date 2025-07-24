//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define constants for maximum input length and maximum number of rooms
#define MAX_INPUT_LENGTH 20
#define MAX_ROOMS 5

// Define struct for a Room
struct Room {
    char name[MAX_INPUT_LENGTH];
    int id;
    int num_connections;
    struct Room *connections[6]; // Maximum of 6 connections per room
    char type[11]; // Start, End, or Mid
};

// Function declarations
int addConnection(struct Room*, struct Room*);
int checkConnectionExists(struct Room*, struct Room*);
int findRoomById(struct Room*, int);
int isRoomComplete(struct Room*);
void playGame(struct Room*);

int main() {
    // Define all 10 possible room names and assign random names to each room
    char *roomNames[10] = {"Kitchen", "Living Room", "Bathroom", "Bedroom", "Dining Room", "Garage", "Attic", "Basement", "Office", "Playroom"};
    int roomNameIds[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) {
        int randIndex = rand() % 10;
        char *tempName = roomNames[i];
        int tempId = roomNameIds[i];
        roomNames[i] = roomNames[randIndex];
        roomNameIds[i] = roomNameIds[randIndex];
        roomNames[randIndex] = tempName;
        roomNameIds[randIndex] = tempId;
    }

    // Create 7 rooms, with 1 start, 1 end, and 5 mid rooms with random names assigned
    struct Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        strcpy(rooms[i].name, roomNames[i+2]);
        rooms[i].id = i;
        rooms[i].num_connections = 0;
        if (i == 0) {
            strcpy(rooms[i].type, "Start");
        } else if (i == 1) {
            strcpy(rooms[i].type, "End");
        } else {
            strcpy(rooms[i].type, "Mid");
        }
    }

    // Generate connections between rooms
    while (1) {
        // Choose random rooms to connect
        int randRoomIndex1 = rand() % MAX_ROOMS;
        int randRoomIndex2 = rand() % MAX_ROOMS;
        struct Room *room1 = &rooms[randRoomIndex1];
        struct Room *room2 = &rooms[randRoomIndex2];

        // Try to connect the rooms
        int result = addConnection(room1, room2);
        if (result == 1) {
            printf("Connection added between %s and %s\n", room1->name, room2->name);
        }

        // Break out of loop if all rooms have enough connections
        int allRoomsComplete = 1;
        for (int i = 0; i < MAX_ROOMS; i++) {
            if (!isRoomComplete(&rooms[i])) {
                allRoomsComplete = 0;
                break;
            }
        }
        if (allRoomsComplete) {
            break;
        }
    }

    // Print out room information for debugging purposes
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d - Name: %s, Type: %s\n", rooms[i].id, rooms[i].name, rooms[i].type);
        for (int j = 0; j < rooms[i].num_connections; j++) {
            printf("Connection %d: Room %d\n", j+1, rooms[i].connections[j]->id);
        }
        printf("\n");
    }

    // Start the game in the Start room
    struct Room *currentRoom = &rooms[0];
    playGame(currentRoom);

    return 0;
}

// Function to add a connection between two rooms
int addConnection(struct Room *room1, struct Room *room2) {
    // Check if connection already exists or if either room has reached maximum connections
    if (checkConnectionExists(room1, room2) || room1->num_connections >= 6 || room2->num_connections >= 6) {
        return 0;
    }

    // Add room2 to room1's connections and vice versa
    room1->connections[room1->num_connections] = room2;
    room2->connections[room2->num_connections] = room1;
    room1->num_connections++;
    room2->num_connections++;

    return 1;
}

// Function to check if a connection already exists between two rooms
int checkConnectionExists(struct Room *room1, struct Room *room2) {
    for (int i = 0; i < room1->num_connections; i++) {
        if (room1->connections[i] == room2) {
            return 1;
        }
    }
    return 0;
}

// Function to find a room by its id
int findRoomById(struct Room *rooms, int id) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to check if a room has enough connections based on its type
int isRoomComplete(struct Room *room) {
    if (strcmp(room->type, "Mid") == 0 && room->num_connections >= 2) {
        return 1;
    } else if ((strcmp(room->type, "Start") == 0 || strcmp(room->type, "End") == 0) && room->num_connections >= 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to play the game
void playGame(struct Room *currentRoom) {
    // Initialize variables for tracking game progress
    struct Room visitedRooms[MAX_ROOMS];
    int numVisitedRooms = 0;
    char path[100];
    int steps = 0;

    // Loop until the End room is reached
    while (strcmp(currentRoom->type, "End") != 0) {
        // Print current room information and prompt user for next room
        printf("CURRENT ROOM: %s\n", currentRoom->name);
        printf("POSSIBLE CONNECTIONS: ");
        for (int i = 0; i < currentRoom->num_connections; i++) {
            printf("%s", currentRoom->connections[i]->name);
            if (i < currentRoom->num_connections-1) {
                printf(", ");
            }
        }
        printf("\nWHERE TO? >");
        
        // Get user input and convert to lowercase
        char input[MAX_INPUT_LENGTH];
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;
        for (int i = 0; input[i]; i++) { 
            input[i] = tolower(input[i]);
        }

        // Check if input is valid and if the chosen room is a valid connection
        int roomIndex = -1;
        for (int i = 0; i < currentRoom->num_connections; i++) {
            if (strcmp(input, currentRoom->connections[i]->name) == 0) {
                roomIndex = findRoomById(currentRoom->connections[i]->connections, currentRoom->id);
                break;
            }
        }
        if (roomIndex == -1) {
            printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
            continue;
        }

        // Update current room
        strcpy(path, strcat(path, currentRoom->name));
        strcat(path, "\n");
        currentRoom = &currentRoom->connections[roomIndex];
        visitedRooms[numVisitedRooms] = *currentRoom;
        numVisitedRooms++;
        steps++;
    }

    // Print game completion message including path and number of steps taken
    printf("CONGRATULATIONS! YOU'VE MADE IT TO THE END.\n");
    printf("PATH TAKEN:\n");
    printf("%s%s\n", path, currentRoom->name);
    printf("YOU TOOK %d STEPS. GOOD JOB!\n", steps);
}