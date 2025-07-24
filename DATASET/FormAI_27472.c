//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>

#define MAX_PLAYERS 4

// Structure to hold player information
typedef struct {
    int id;
    bool is_online;
    int current_room;
    int current_light_state;
} Player;

// Structure to hold room information
typedef struct {
    int id;
    bool is_lit;
} Room;

// Global variables
Player players[MAX_PLAYERS];
Room rooms[3] = {{0, false}, {1, false}, {2, false}};

// Function to update the room light state based on player input
void updateRoomLightState(int player_id, int room_id, bool is_lit) {
    // Update the room light state
    rooms[room_id].is_lit = is_lit;

    // Update the current light state for the player
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].id == player_id) {
            players[i].current_light_state = is_lit;
            break;
        }
    }
}

// Function to handle player input
void handlePlayerInput(int player_id, int room_id, bool is_lit) {
    // Check if the player is online
    if (!players[player_id].is_online) {
        printf("Player %d is not online.\n", player_id);
        return;
    }

    // Check if the room exists
    if (room_id < 0 || room_id > 2) {
        printf("Room %d does not exist.\n", room_id);
        return;
    }

    // Update the room light state
    updateRoomLightState(player_id, room_id, is_lit);

    // Print the current room and light state for all players
    printf("Room Status:\n");
    for (int i = 0; i < 3; i++) {
        printf("Room %d: %s\n", rooms[i].id, rooms[i].is_lit ? "On" : "Off");
    }
    printf("\n");

    // Update the current room for the player
    players[player_id].current_room = room_id;

    // Print the updated player information for all players
    printf("Player Status:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].is_online) {
            printf("Player %d is in room %d and the light is %s.\n", players[i].id, players[i].current_room, players[i].current_light_state ? "On" : "Off");
        }
    }
}

int main() {
    // Initialize the players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i;
        players[i].is_online = true;
        players[i].current_room = 0;
        players[i].current_light_state = false;
    }

    // Print the initial room and player status
    printf("Room Status:\n");
    for (int i = 0; i < 3; i++) {
        printf("Room %d: %s\n", rooms[i].id, rooms[i].is_lit ? "On" : "Off");
    }
    printf("\n");

    printf("Player Status:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].is_online) {
            printf("Player %d is in room %d and the light is %s.\n", players[i].id, players[i].current_room, players[i].current_light_state ? "On" : "Off");
        }
    }
    printf("\n");

    // Simulate player input
    handlePlayerInput(0, 1, true);
    handlePlayerInput(1, 2, true);
    handlePlayerInput(2, 0, true);
    handlePlayerInput(3, 2, false);

    return 0;
}