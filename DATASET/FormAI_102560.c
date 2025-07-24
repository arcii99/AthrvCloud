//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 50

typedef struct Room Room;

struct Room {
    int id;
    char* name;
    char* description;
    Room** connections;
    int numConnections;
};

// Global variables
Room* currentRoom;
Room** allRooms;
int numRooms;

// Helper function to create a room
Room* createRoom(int id, char* name, char* description) {
    Room* newRoom = malloc(sizeof(Room));
    newRoom->id = id;
    newRoom->name = name;
    newRoom->description = description;
    newRoom->numConnections = 0;
    newRoom->connections = malloc(sizeof(Room*) * 6); // Maximum number of connections is 6
    return newRoom;
}

// Helper function to connect two rooms
void connectRooms(Room* room1, Room* room2) {
    room1->connections[room1->numConnections] = room2;
    room1->numConnections++;
    room2->connections[room2->numConnections] = room1;
    room2->numConnections++;
}

// Helper function to initialize the game
void initializeGame() {
    Room* room0 = createRoom(0, "Entrance Hall", "You find yourself in the entrance hall of an old castle. You can see several doors leading to other parts of the castle.");
    Room* room1 = createRoom(1, "Kitchen", "You are in the castle's kitchen. There are pots and pans scattered around and the distinct smell of food lingers in the air.");
    Room* room2 = createRoom(2, "Dungeon", "You descend a staircase into a dark, damp dungeon. Chains hang from the walls and you can hear the faint dripping of water.");
    Room* room3 = createRoom(3, "Great Hall", "You enter a grand hall filled with paintings and tapestries. At the far end of the room, a large throne sits empty.");
    Room* room4 = createRoom(4, "Bedroom", "You find yourself in a comfortable bedroom. A large four-poster bed dominates the center of the room.");
    Room* room5 = createRoom(5, "Library", "You step into a grand library filled with shelves of books. The smell of old parchment fills the air.");

    connectRooms(room0, room1);
    connectRooms(room1, room2);
    connectRooms(room1, room3);
    connectRooms(room3, room4);
    connectRooms(room3, room5);

    numRooms = 6;
    allRooms = malloc(sizeof(Room*) * numRooms);
    allRooms[0] = room0;
    allRooms[1] = room1;
    allRooms[2] = room2;
    allRooms[3] = room3;
    allRooms[4] = room4;
    allRooms[5] = room5;

    currentRoom = room0;
}

// Helper function to print the current room's description and possible connections
void printRoomInfo() {
    printf("%s\n", currentRoom->description);
    printf("Possible connections:\n");
    for (int i = 0; i < currentRoom->numConnections; i++) {
        printf("%s\n", currentRoom->connections[i]->name);
    }
}

// Helper function to move the player to a new room
void moveToRoom(char* roomName) {
    for (int i = 0; i < currentRoom->numConnections; i++) {
        if (strcmp(roomName, currentRoom->connections[i]->name) == 0) {
            currentRoom = currentRoom->connections[i];
            return;
        }
    }
    printf("Cannot move to that room.\n");
}

// Thread function to handle user input
void* getInput(void* arg) {
    char input[MAX_INPUT_SIZE];
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        strtok(input, "\n"); // Remove newline character
        moveToRoom(input);
    }
    return NULL;
}

int main() {
    initializeGame();
    pthread_t inputThread;
    pthread_create(&inputThread, NULL, getInput, NULL);

    while (1) {
        printRoomInfo();
        sleep(1); // Delay between printing room info
    }

    pthread_join(inputThread, NULL);

    return 0;
}