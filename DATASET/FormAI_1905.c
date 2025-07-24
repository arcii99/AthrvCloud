//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    int x;
    int y;
    char symbol;
} Entity;

typedef struct {
    char map[MAP_HEIGHT][MAP_WIDTH];
    Entity entities[10];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} GameState;

void init_game(GameState *state) {
    // Initialize the game state
    state->num_rooms = 0;

    // Fill the map with walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            state->map[y][x] = '#';
        }
    }
}

int generate_room_size() {
    // Generate a random room size between MIN_ROOM_SIZE and MAX_ROOM_SIZE
    return rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
}

int is_room_overlap(Room *room1, Room *room2) {
    // Check if the given rooms overlap
    return (room1->x < room2->x + room2->width &&
            room1->x + room1->width > room2->x &&
            room1->y < room2->y + room2->height &&
            room1->y + room1->height > room2->y);
}

void generate_rooms(GameState *state) {
    // Generate rooms until we have reached the maximum number of rooms or can't generate any more
    for (int i = 0; i < MAX_ROOMS; i++) {
        int room_x = rand() % (MAP_WIDTH - MAX_ROOM_SIZE - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - MAX_ROOM_SIZE - 1) + 1;
        int room_width = generate_room_size();
        int room_height = generate_room_size();

        Room new_room = {room_x, room_y, room_width, room_height};

        // Check if the new room overlaps with any existing rooms
        int is_overlap = 0;
        for (int j = 0; j < state->num_rooms; j++) {
            if (is_room_overlap(&new_room, &state->rooms[j])) {
                is_overlap = 1;
                break;
            }
        }

        if (!is_overlap) {
            // Add the new room to the game state
            state->rooms[state->num_rooms] = new_room;
            state->num_rooms++;

            // Fill the room with floor tiles
            for (int y = new_room.y + 1; y < new_room.y + new_room.height - 1; y++) {
                for (int x = new_room.x + 1; x < new_room.x + new_room.width - 1; x++) {
                    state->map[y][x] = '.';
                }
            }
        }
    }
}

void spawn_player(GameState *state) {
    // Spawn the player at a random location in the first room
    Room first_room = state->rooms[0];
    int player_x = rand() % (first_room.width - 2) + first_room.x + 1;
    int player_y = rand() % (first_room.height - 2) + first_room.y + 1;

    Entity player = {player_x, player_y, '@'};
    state->entities[0] = player;
}

void print_map(GameState *state) {
    // Print the game map to the console
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int has_entity = 0;
            for (int i = 0; i < 10; i++) {
                if (state->entities[i].x == x && state->entities[i].y == y) {
                    printf("%c", state->entities[i].symbol);
                    has_entity = 1;
                    break;
                }
            }
            if (!has_entity) {
                printf("%c", state->map[y][x]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    GameState state;

    init_game(&state);
    generate_rooms(&state);
    spawn_player(&state);
    print_map(&state);

    return 0;
}