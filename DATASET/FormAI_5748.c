//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the game
#define MAP_SIZE 10
#define MAX_ROOMS 5
#define MAX_MONSTERS 10

// Struct for storing coordinates
typedef struct {
    int x;
    int y;
} Coords;

// Enum for cell types
typedef enum {
    WALL,
    FLOOR,
    DOOR,
    HALLWAY
} CellType;

// Struct for storing a single cell
typedef struct {
    CellType type;
    int room_id;
} Cell;

// Struct for storing a room
typedef struct {
    int id;
    Coords pos;
    int width;
    int height;
} Room;

// Struct for storing a monster
typedef struct {
    Coords pos;
    char symbol;
} Monster;

// Function declarations
void generate_dungeon(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int *num_rooms);
void generate_rooms(Room *rooms, int *num_rooms);
void place_rooms(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int num_rooms);
int is_valid_room(Cell dungeon[MAP_SIZE][MAP_SIZE], Room room);
void generate_hallways(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int num_rooms);
void place_hallway(Cell dungeon[MAP_SIZE][MAP_SIZE], Coords start_pos, Coords end_pos);
void generate_monsters(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int *num_monsters);
void place_monsters(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int num_monsters);
void print_dungeon(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int num_monsters);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the dungeon and rooms
    Cell dungeon[MAP_SIZE][MAP_SIZE];
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    generate_dungeon(dungeon, rooms, &num_rooms);

    // Create the monsters
    Monster monsters[MAX_MONSTERS];
    int num_monsters = 0;
    generate_monsters(dungeon, monsters, &num_monsters);

    // Place the monsters in the dungeon
    place_monsters(dungeon, monsters, num_monsters);

    // Print the dungeon and monsters
    print_dungeon(dungeon, monsters, num_monsters);

    return 0;
}

void generate_dungeon(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int *num_rooms) {
    // Initialize all cells to walls
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            dungeon[x][y].type = WALL;
            dungeon[x][y].room_id = -1;
        }
    }

    // Generate the rooms and place them in the dungeon
    generate_rooms(rooms, num_rooms);
    place_rooms(dungeon, rooms, *num_rooms);

    // Generate the hallways and connect the rooms
    generate_hallways(dungeon, rooms, *num_rooms);
}

void generate_rooms(Room *rooms, int *num_rooms) {
    // Generate a random number of rooms up to MAX_ROOMS
    *num_rooms = rand() % MAX_ROOMS + 1;

    // Generate each room
    for (int i = 0; i < *num_rooms; i++) {
        rooms[i].id = i;
        rooms[i].width = rand() % 5 + 3;
        rooms[i].height = rand() % 5 + 3;
        rooms[i].pos.x = rand() % (MAP_SIZE - rooms[i].width - 1) + 1;
        rooms[i].pos.y = rand() % (MAP_SIZE - rooms[i].height - 1) + 1;
    }
}

void place_rooms(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int num_rooms) {
    // Place each room in the dungeon
    for (int i = 0; i < num_rooms; i++) {
        // Check if the room is valid
        if (is_valid_room(dungeon, rooms[i])) {
            // Place the room
            for (int x = rooms[i].pos.x; x < rooms[i].pos.x + rooms[i].width; x++) {
                for (int y = rooms[i].pos.y; y < rooms[i].pos.y + rooms[i].height; y++) {
                    dungeon[x][y].type = FLOOR;
                    dungeon[x][y].room_id = i;
                }
            }
        }
    }
}

int is_valid_room(Cell dungeon[MAP_SIZE][MAP_SIZE], Room room) {
    // Check if the room overlaps with another room
    for (int x = room.pos.x - 1; x <= room.pos.x + room.width; x++) {
        for (int y = room.pos.y - 1; y <= room.pos.y + room.height; y++) {
            if (dungeon[x][y].type != WALL) {
                return 0;
            }
        }
    }

    return 1;
}

void generate_hallways(Cell dungeon[MAP_SIZE][MAP_SIZE], Room *rooms, int num_rooms) {
    // Generate a hallway between each pair of rooms
    for (int i = 0; i < num_rooms; i++) {
        // Find the center of the current room
        Coords room_center;
        room_center.x = rooms[i].pos.x + rooms[i].width / 2;
        room_center.y = rooms[i].pos.y + rooms[i].height / 2;

        // Generate a hallway to each other room
        for (int j = i + 1; j < num_rooms; j++) {
            // Find the center of the current room
            Coords other_room_center;
            other_room_center.x = rooms[j].pos.x + rooms[j].width / 2;
            other_room_center.y = rooms[j].pos.y + rooms[j].height / 2;

            // Place the hallway
            place_hallway(dungeon, room_center, other_room_center);
        }
    }
}

void place_hallway(Cell dungeon[MAP_SIZE][MAP_SIZE], Coords start_pos, Coords end_pos) {
    // Determine the direction of the hallway
    int dx = end_pos.x - start_pos.x;
    int dy = end_pos.y - start_pos.y;
    int abs_dx = abs(dx);
    int abs_dy = abs(dy);
    int x_dir = dx / abs_dx;
    int y_dir = dy / abs_dy;

    // Place each cell along the hallway
    Coords current_pos = start_pos;
    while (current_pos.x != end_pos.x || current_pos.y != end_pos.y) {
        // Place a floor cell
        dungeon[current_pos.x][current_pos.y].type = HALLWAY;

        // Move to the next cell
        if (rand() % 2 == 0 && current_pos.x != end_pos.x) {
            current_pos.x += x_dir;
        } else if (current_pos.y != end_pos.y) {
            current_pos.y += y_dir;
        }
    }

    // Place the final floor cell
    dungeon[current_pos.x][current_pos.y].type = HALLWAY;
}

void generate_monsters(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int *num_monsters) {
    // Generate a random number of monsters up to MAX_MONSTERS
    *num_monsters = rand() % MAX_MONSTERS + 1;

    // Generate each monster
    for (int i = 0; i < *num_monsters; i++) {
        monsters[i].symbol = 'M';
        monsters[i].pos.x = rand() % MAP_SIZE;
        monsters[i].pos.y = rand() % MAP_SIZE;

        // Make sure the monster is not in a wall
        while (dungeon[monsters[i].pos.x][monsters[i].pos.y].type == WALL) {
            monsters[i].pos.x = rand() % MAP_SIZE;
            monsters[i].pos.y = rand() % MAP_SIZE;
        }
    }
}

void place_monsters(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int num_monsters) {
    // Place each monster in the dungeon
    for (int i = 0; i < num_monsters; i++) {
        // Place the monster in a random empty cell
        while (dungeon[monsters[i].pos.x][monsters[i].pos.y].type != FLOOR) {
            monsters[i].pos.x = rand() % MAP_SIZE;
            monsters[i].pos.y = rand() % MAP_SIZE;
        }
    }
}

void print_dungeon(Cell dungeon[MAP_SIZE][MAP_SIZE], Monster *monsters, int num_monsters) {
    // Print the dungeon
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (dungeon[x][y].type == WALL) {
                printf("#");
            } else if (dungeon[x][y].type == FLOOR) {
                printf(".");
            } else if (dungeon[x][y].type == DOOR) {
                printf("+");
            } else if (dungeon[x][y].type == HALLWAY) {
                printf("-");
            }

            // Print any monsters in the cell
            for (int i = 0; i < num_monsters; i++) {
                if (monsters[i].pos.x == x && monsters[i].pos.y == y) {
                    printf("%c", monsters[i].symbol);
                }
            }
        }
        printf("\n");
    }
}