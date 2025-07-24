//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10 // maximum number of rooms in the haunted house
#define MAX_PLAYERS 5 // maximum number of players in the game
#define MAX_NAME_LENGTH 20

// struct to represent a room in the haunted house
typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_ghost_present;
    int is_occupied;
} Room;

// struct to represent a player in the game
typedef struct {
    char name[MAX_NAME_LENGTH];
    int current_room_index;
} Player;

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    Room rooms[MAX_ROOMS]; // array of rooms in the haunted house
    int num_rooms = 0; // number of rooms in the haunted house
    Player players[MAX_PLAYERS]; // array of players in the game
    int num_players = 0; // number of players in the game

    // populate rooms array with random room names and random ghost presence/absence
    char room_names[][MAX_NAME_LENGTH] = {"Kitchen", "Living room", "Bedroom", "Attic", "Basement", "Bathroom", "Study", "Library", "Dining room", "Foyer"};
    for (int i = 0; i < MAX_ROOMS; i++) {
        strcpy(rooms[i].name, room_names[rand() % 10]);
        rooms[i].is_ghost_present = rand() % 2;
        rooms[i].is_occupied = 0;
        num_rooms++;
    }

    // get player names and assign them to random rooms
    char player_name[MAX_NAME_LENGTH];
    printf("Enter player names (up to %d players, stop with empty string):\n", MAX_PLAYERS);
    while (num_players < MAX_PLAYERS) {
        fgets(player_name, MAX_NAME_LENGTH, stdin);
        if (player_name[0] == '\n') {
            break;
        }
        sscanf(player_name, "%s", players[num_players].name);
        players[num_players].current_room_index = rand() % num_rooms;
        rooms[players[num_players].current_room_index].is_occupied = 1;
        num_players++;
    }

    // main game loop
    int game_over = 0;
    while (!game_over) {
        // print current room status
        printf("Haunted House\n");
        for (int i = 0; i < num_rooms; i++) {
            Room room = rooms[i];
            printf("%s - %s %s\n", room.name, room.is_ghost_present ? "Ghost present" : "Ghost absent", room.is_occupied ? "Occupied" : "Unoccupied");
        }
        printf("\n");

        // get player move choice
        printf("Player moves (up to %d characters):\n", MAX_NAME_LENGTH);
        char move[MAX_NAME_LENGTH];
        fgets(move, MAX_NAME_LENGTH, stdin);
        if (move[0] == '\n') {
            continue;
        }
        sscanf(move, "%s", move);

        // move players and handle ghost encounters
        for (int i = 0; i < num_players; i++) {
            Player player = players[i];
            if (strcmp(move, player.name) == 0) {
                int prev_room_index = player.current_room_index;
                int new_room_index = rand() % num_rooms;
                while (new_room_index == prev_room_index || rooms[new_room_index].is_occupied) {
                    new_room_index = rand() % num_rooms;
                }
                players[i].current_room_index = new_room_index;
                rooms[prev_room_index].is_occupied = 0;
                rooms[new_room_index].is_occupied = 1;
                if (rooms[new_room_index].is_ghost_present) {
                    printf("%s encountered a ghost in the %s!\n", player.name, rooms[new_room_index].name);
                    game_over = 1;
                    break;
                }
            }
        }
    }

    // game over
    printf("Game over.\n");
    return 0;
}