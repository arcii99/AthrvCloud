//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_ROOMS 10

// Define a room struct to hold room information
typedef struct {
    int id;
    char name[20];
    char description[100];
} Room;

// Define a player struct to hold player information
typedef struct {
    int id;
    char name[20];
    int current_room_id;
} Player;

// Define function to generate a random room with an id and name
Room generate_random_room(int id) {
    Room room;
    room.id = id;
    sprintf(room.name, "Room %d", id);
    sprintf(room.description, "This is %s. It is a spooky room!", room.name);
    return room;
}

int main() {
    srand(time(NULL));

    // Generate random rooms
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = generate_random_room(i+1);
    }

    // Initialize players
    Player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i+1;
        sprintf(players[i].name, "Player %d", players[i].id);
        players[i].current_room_id = rand() % MAX_ROOMS + 1;
    }

    // Game loop
    int game_over = 0;
    while (!game_over) {

        // Print current room information for each player
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s is in %s\n", players[i].name, rooms[players[i].current_room_id-1].name);
        }

        // Move players randomly to a new room
        for (int i = 0; i < MAX_PLAYERS; i++) {
            players[i].current_room_id = rand() % MAX_ROOMS + 1;
        }

        // Wait for input to continue game loop
        char input[10];
        printf("Press enter to continue...");
        fgets(input, 10, stdin);
    }

    return 0;
}