//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_PLAYERS 5
#define MAX_ROOM_DESC 100
#define MAX_PLAYER_NAME 20
#define MAX_COMMAND 20

// Function to get player input
void getInput(char *input) {
    printf("> ");
    fgets(input, MAX_COMMAND, stdin);
}

// Function to trim newline character from string
void trimNewline(char *string) {
    int len = strlen(string);
    if (string[len-1] == '\n') {
        string[len-1] = '\0';
    }
}

// Room struct
typedef struct {
    char name[MAX_PLAYER_NAME];
    char desc[MAX_ROOM_DESC];
    int connections[MAX_ROOMS];
    int num_connections;
} Room;

// Player struct
typedef struct {
    char name[MAX_PLAYER_NAME];
    int current_room;
} Player;

// Global variables
Room rooms[MAX_ROOMS];
Player players[MAX_PLAYERS];
int num_rooms = 0;
int num_players = 0;

// Function to add a room
void addRoom(char *name, char *desc) {
    Room new_room;
    strcpy(new_room.name, name);
    strcpy(new_room.desc, desc);
    new_room.num_connections = 0;
    rooms[num_rooms++] = new_room;
}

// Function to add a connection between two rooms
void addConnection(int room1, int room2) {
    rooms[room1].connections[rooms[room1].num_connections++] = room2;
    rooms[room2].connections[rooms[room2].num_connections++] = room1;
}

// Function to print a room's connections
void printConnections(int room_index) {
    printf("Connections:\n");
    for (int i = 0; i < rooms[room_index].num_connections; i++) {
        printf("    %s\n", rooms[rooms[room_index].connections[i]].name);
    }
}

// Function to print a player's current room
void printCurrentRoom(int player_index) {
    printf("%s is in %s.\n", players[player_index].name, rooms[players[player_index].current_room].name);
    printf("%s\n", rooms[players[player_index].current_room].desc);
    printConnections(players[player_index].current_room);
}

int main() {
    // Initialize rooms
    addRoom("Hallway", "A long, dimly lit hallway.");
    addRoom("Kitchen", "A large kitchen with pots and pans strewn about.");
    addRoom("Living Room", "A cozy living room with a fireplace and comfy chairs.");
    addConnection(0, 1);
    addConnection(1, 2);

    // Initialize players
    Player new_player;
    strcpy(new_player.name, "Player 1");
    new_player.current_room = 0;
    players[num_players++] = new_player;

    // Main game loop
    char input[MAX_COMMAND];
    while(1) {
        // Print current room and prompt for command
        printCurrentRoom(0);
        getInput(input);
        trimNewline(input);

        // Parse command
        if (strcmp(input, "north") == 0) {
            if (rooms[players[0].current_room].connections[0] != -1) {
                players[0].current_room = rooms[players[0].current_room].connections[0];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "south") == 0) {
            if (rooms[players[0].current_room].connections[1] != -1) {
                players[0].current_room = rooms[players[0].current_room].connections[1];
            } else {
                printf("You can't go that way.\n");
            }
        } else if (strcmp(input, "look") == 0) {
            printCurrentRoom(0);
        } else {
            printf("Command not recognized.\n");
        }
    }

    return 0;
}