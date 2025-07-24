//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// initialize constants for board dimensions and dungeon generation
#define BOARD_WIDTH 80
#define BOARD_HEIGHT 24
#define ROOM_MAX_SIZE 10
#define ROOM_MIN_SIZE 6
#define MAX_ROOMS 30

// structure for a room on the board
typedef struct {
    int x, y, width, height;
} Room;

// structure for a cell in the board
typedef struct {
    int value, discovered;
} Cell;

// initialize global variables for the board and dungeon generation
Cell board[BOARD_HEIGHT][BOARD_WIDTH];
Room rooms[MAX_ROOMS];
int num_rooms;

// initialize functions for dungeon generation
void generate_dungeon();
int add_room(int x, int y, int width, int height);
int get_random_integer(int min, int max);
void add_corridor(int start_x, int start_y, int end_x, int end_y);

int main() {
    // seed the random number generator with the current time
    srand(time(NULL));

    // generate the dungeon
    generate_dungeon();

    // print the board
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            if (board[y][x].value == 1) {
                putchar('#');
            } else if (board[y][x].value == 2) {
                putchar('.');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}

void generate_dungeon() {
    // initialize the board to all walls and undiscovered cells
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x].value = 1;
            board[y][x].discovered = 0;
        }
    }

    // add a random number of rooms to the board
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = get_random_integer(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int height = get_random_integer(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int x = get_random_integer(0, BOARD_WIDTH - width - 1);
        int y = get_random_integer(0, BOARD_HEIGHT - height - 1);
        if (add_room(x, y, width, height)) {
            num_rooms++;
        }
    }

    // connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        int start_x = get_random_integer(rooms[i].x, rooms[i].x + rooms[i].width);
        int start_y = get_random_integer(rooms[i].y, rooms[i].y + rooms[i].height);
        int end_x = get_random_integer(rooms[i + 1].x, rooms[i + 1].x + rooms[i + 1].width);
        int end_y = get_random_integer(rooms[i + 1].y, rooms[i + 1].y + rooms[i + 1].height);
        add_corridor(start_x, start_y, end_x, end_y);
    }
}

int add_room(int x, int y, int width, int height) {
    // check if the room would intersect with any existing rooms
    for (int i = 0; i < num_rooms; i++) {
        if (x < rooms[i].x + rooms[i].width && x + width > rooms[i].x &&
                y < rooms[i].y + rooms[i].height && y + height > rooms[i].y) {
            return 0;
        }
    }

    // add the room to the board
    for (int j = y; j < y + height; j++) {
        for (int i = x; i < x + width; i++) {
            board[j][i].value = 2;
        }
    }

    // add the room to the array of rooms
    rooms[num_rooms].x = x;
    rooms[num_rooms].y = y;
    rooms[num_rooms].width = width;
    rooms[num_rooms].height = height;

    return 1;
}

int get_random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void add_corridor(int start_x, int start_y, int end_x, int end_y) {
    // randomly decide whether to start by moving horizontally or vertically
    if (rand() % 2 == 1) {
        // move horizontally first, then vertically
        int step_x = (start_x < end_x) ? 1 : -1;
        int distance_x = abs(start_x - end_x);
        for (int i = 0; i < distance_x; i++) {
            start_x += step_x;
            board[start_y][start_x].value = 2;
        }
        int step_y = (start_y < end_y) ? 1 : -1;
        int distance_y = abs(start_y - end_y);
        for (int i = 0; i < distance_y; i++) {
            start_y += step_y;
            board[start_y][start_x].value = 2;
        }
    } else {
        // move vertically first, then horizontally
        int step_y = (start_y < end_y) ? 1 : -1;
        int distance_y = abs(start_y - end_y);
        for (int i = 0; i < distance_y; i++) {
            start_y += step_y;
            board[start_y][start_x].value = 2;
        }
        int step_x = (start_x < end_x) ? 1 : -1;
        int distance_x = abs(start_x - end_x);
        for (int i = 0; i < distance_x; i++) {
            start_x += step_x;
            board[start_y][start_x].value = 2;
        }
    }
}