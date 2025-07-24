//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_ROOMS 6
#define MIN_ROOM_WIDTH 3
#define MIN_ROOM_HEIGHT 3

typedef struct {
    int x;
    int y;
} RoomCorner;

typedef struct {
    RoomCorner top_left;
    int width;
    int height;
} Room;

typedef struct {
    int x;
    int y;
    bool visited;
} Cell;

typedef struct {
    Cell cells[HEIGHT][WIDTH];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Dungeon;

void generate_dungeon(Dungeon *dungeon);
void print_dungeon(Dungeon dungeon);
void init_cells(Dungeon *dungeon);
void create_rooms(Dungeon *dungeon);
bool check_room_collisions(Dungeon dungeon, Room room);
bool check_cell_collisions(Dungeon dungeon, Room room, int corner_x, int corner_y);
void place_room(Dungeon *dungeon, Room room);
void tunnel_between_rooms(Dungeon *dungeon, Room *room1, Room *room2);
void tunnel_between_cells(Dungeon *dungeon, int x1, int y1, int x2, int y2);

int main() {
    srand(time(NULL));
    Dungeon dungeon;

    generate_dungeon(&dungeon);
    print_dungeon(dungeon);

    return 0;
}

void generate_dungeon(Dungeon *dungeon) {
    init_cells(dungeon);
    create_rooms(dungeon);

    for (int i = 0; i < dungeon->num_rooms - 1; i++) {
        tunnel_between_rooms(dungeon, &dungeon->rooms[i], &dungeon->rooms[i + 1]);
    }
}

void print_dungeon(Dungeon dungeon) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool found_room = false;

            for (int i = 0; i < dungeon.num_rooms; i++) {
                Room room = dungeon.rooms[i];

                if (x >= room.top_left.x && x < room.top_left.x + room.width &&
                    y >= room.top_left.y && y < room.top_left.y + room.height) {

                    printf(".");
                    found_room = true;
                    break;
                }
            }

            if (!found_room) {
                printf("#");
            }
        }
        printf("\n");
    }
}

void init_cells(Dungeon *dungeon) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon->cells[y][x].x = x;
            dungeon->cells[y][x].y = y;
            dungeon->cells[y][x].visited = false;
        }
    }
}

void create_rooms(Dungeon *dungeon) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % (WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        int height = rand() % (HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        int x = rand() % (WIDTH - width);
        int y = rand() % (HEIGHT - height);

        Room room = { { x, y }, width, height };

        if (!check_room_collisions(*dungeon, room)) {
            dungeon->rooms[dungeon->num_rooms] = room;
            dungeon->num_rooms++;
            place_room(dungeon, room);
        }
    }
}

bool check_room_collisions(Dungeon dungeon, Room room) {
    for (int i = 0; i < dungeon.num_rooms; i++) {
        Room existing_room = dungeon.rooms[i];

        if (room.top_left.x + room.width >= existing_room.top_left.x &&
            room.top_left.x <= existing_room.top_left.x + existing_room.width &&
            room.top_left.y + room.height >= existing_room.top_left.y &&
            room.top_left.y <= existing_room.top_left.y + existing_room.height) {

            return true;
        }
    }

    return false;
}

bool check_cell_collisions(Dungeon dungeon, Room room, int corner_x, int corner_y) {
    for (int y = room.top_left.y - 1; y <= room.top_left.y + room.height; y++) {
        for (int x = room.top_left.x - 1; x <= room.top_left.x + room.width; x++) {
            if (corner_x == x && corner_y == y) {
                return true;
            }

            if (corner_x == x - 1 && corner_y == y &&
                dungeon.cells[y][x - 1].visited && dungeon.cells[y][x].visited) {

                return true;
            }

            if (corner_x == x && corner_y == y - 1 &&
                dungeon.cells[y - 1][x].visited && dungeon.cells[y][x].visited) {

                return true;
            }
        }
    }

    return false;
}

void place_room(Dungeon *dungeon, Room room) {
    for (int y = room.top_left.y; y < room.top_left.y + room.height; y++) {
        for (int x = room.top_left.x; x < room.top_left.x + room.width; x++) {
            dungeon->cells[y][x].visited = true;
        }
    }
}

void tunnel_between_rooms(Dungeon *dungeon, Room *room1, Room *room2) {
    int x1 = rand() % room1->width + room1->top_left.x;
    int y1 = rand() % room1->height + room1->top_left.y;
    int x2 = rand() % room2->width + room2->top_left.x;
    int y2 = rand() % room2->height + room2->top_left.y;

    if (x1 < x2) {
        tunnel_between_cells(dungeon, x1, y1, x2, y1);
        tunnel_between_cells(dungeon, x2, y1, x2, y2);
    } else {
        tunnel_between_cells(dungeon, x1, y1, x1, y2);
        tunnel_between_cells(dungeon, x1, y2, x2, y2);
    }
}

void tunnel_between_cells(Dungeon *dungeon, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int y_min = y1 < y2 ? y1 : y2;
        int y_max = y1 < y2 ? y2 : y1;

        for (int y = y_min; y <= y_max; y++) {
            dungeon->cells[y][x1].visited = true;
        }
    } else {
        int x_min = x1 < x2 ? x1 : x2;
        int x_max = x1 < x2 ? x2 : x1;

        for (int x = x_min; x <= x_max; x++) {
            dungeon->cells[y1][x].visited = true;
        }
    }
}