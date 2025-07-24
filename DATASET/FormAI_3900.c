//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROOMS 5
#define MAX_ROOM_SIZE 6

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// Function prototypes
void generate_map(char map[][MAP_SIZE]);
void print_map(char map[][MAP_SIZE]);
void add_room(Room* rooms, int* num_rooms);
int is_room_valid(Room* room, Room rooms[], int num_rooms);
void connect_rooms(Room* rooms, int num_rooms, char map[][MAP_SIZE]);

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    srand(time(NULL));  // Initialize random seed
    generate_map(map);
    print_map(map);
    return 0;
}

void generate_map(char map[][MAP_SIZE]) {
    int x, y, i, j;
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    // Initialize map to be all walls
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
    // Generate rooms
    while (num_rooms < MAX_ROOMS) {
        add_room(&rooms[num_rooms], &num_rooms);
    }
    // Connect rooms with hallways
    connect_rooms(rooms, num_rooms, map);
    // Place player at a random location
    x = rand() % MAP_SIZE;
    y = rand() % MAP_SIZE;
    map[y][x] = '@';
}

void print_map(char map[][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void add_room(Room* rooms, int* num_rooms) {
    int x, y, width, height;
    // Generate random room dimensions
    width = rand() % MAX_ROOM_SIZE + 2;
    height = rand() % MAX_ROOM_SIZE + 2;
    // Generate random room position
    x = rand() % (MAP_SIZE - width - 1) + 1;
    y = rand() % (MAP_SIZE - height - 1) + 1;
    rooms->x = x;
    rooms->y = y;
    rooms->width = width;
    rooms->height = height;
    if (is_room_valid(rooms, rooms - *num_rooms, *num_rooms)) {
        (*num_rooms)++;
    }
}

int is_room_valid(Room* room, Room rooms[], int num_rooms) {
    int i;
    // Check if room overlaps with other rooms
    for (i = 0; i < num_rooms; i++) {
        if (room->x < rooms[i].x + rooms[i].width &&
            room->x + room->width > rooms[i].x &&
            room->y < rooms[i].y + rooms[i].height &&
            room->y + room->height > rooms[i].y) {
            return 0;
        }
    }
    // If room is valid, add it to the array of rooms
    for (i = room->y; i < room->y + room->height; i++) {
        int j;
        for (j = room->x; j < room->x + room->width; j++) {
            // Place room walls at the edges of the room
            if (i == room->y || i == room->y + room->height - 1 ||
                j == room->x || j == room->x + room->width - 1) {
                rooms[num_rooms].x = j;
                rooms[num_rooms].y = i;
                rooms[num_rooms].width = 1;
                rooms[num_rooms].height = 1;
                num_rooms++;
            }
        }
    }
    // All good
    return 1;
}

void connect_rooms(Room* rooms, int num_rooms, char map[][MAP_SIZE]) {
    int i, j;
    // Create a hallway between each adjacent room
    for (i = 1; i < num_rooms; i++) {
        int x1 = rooms[i - 1].x + rooms[i - 1].width / 2;
        int y1 = rooms[i - 1].y + rooms[i - 1].height / 2;
        int x2 = rooms[i].x + rooms[i].width / 2;
        int y2 = rooms[i].y + rooms[i].height / 2;
        // Generate horizontal hallway
        if (rand() % 2 == 0) {
            for (j = x1; j != x2; j += x2 > x1 ? 1 : -1) {
                map[y1][j] = '.';
            }
            for (j = y1; j != y2; j += y2 > y1 ? 1 : -1) {
                map[j][x2] = '.';
            }
        }
        // Generate vertical hallway
        else {
            for (j = y1; j != y2; j += y2 > y1 ? 1 : -1) {
                map[j][x1] = '.';
            }
            for (j = x1; j != x2; j += x2 > x1 ? 1 : -1) {
                map[y2][j] = '.';
            }
        }
    }
}