//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 20
#define COLS 40
#define MAX_ROOM_SIZE 12
#define MIN_ROOM_SIZE 6

char map[ROWS][COLS];

typedef struct {
    int x, y, width, height;
} Room;

int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void create_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
}

void print_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void create_room(Room r) {
    for (int i = r.x; i < r.x + r.width; i++) {
        for (int j = r.y; j < r.y + r.height; j++) {
            map[i][j] = '.';
        }
    }
}

bool is_overlap(Room r1, Room r2) {
    int r1_x1 = r1.x;
    int r1_x2 = r1.x + r1.width;
    int r1_y1 = r1.y;
    int r1_y2 = r1.y + r1.height;
    
    int r2_x1 = r2.x;
    int r2_x2 = r2.x + r2.width;
    int r2_y1 = r2.y;
    int r2_y2 = r2.y + r2.height;
    
    if (r1_x1 <= r2_x2 && r1_x2 >= r2_x1 && r1_y1 <= r2_y2 && r1_y2 >= r2_y1) {
        return true;
    }
    return false;
}

void connect_rooms(Room r1, Room r2) {
    int r1_x = r1.x + r1.width/2;
    int r1_y = r1.y + r1.height/2;
    
    int r2_x = r2.x + r2.width/2;
    int r2_y = r2.y + r2.height/2;
    
    while (r1_x != r2_x) {
        if (r1_x < r2_x) {
            r1_x++;
        } else {
            r1_x--;
        }
        map[r1_x][r1_y] = '.';
    }
    
    while (r1_y != r2_y) {
        if (r1_y < r2_y) {
            r1_y++;
        } else {
            r1_y--;
        }
        map[r1_x][r1_y] = '.';
    }
}

void generate_map() {
    int num_rooms = 6;
    int room_count = 0;
    int max_iterations = 1000;
    int iteration_count = 0;
    
    Room rooms[num_rooms];
    
    srand(time(NULL));
    
    create_map();
    
    while (room_count < num_rooms && iteration_count < max_iterations) {
        int w = get_random(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int h = get_random(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int x = get_random(0, COLS - w);
        int y = get_random(0, ROWS - h);
        Room r = { x, y, w, h };
        bool overlap = false;
        
        for (int i = 0; i < room_count; i++) {
            if (is_overlap(r, rooms[i])) {
                overlap = true;
                break;
            }
        }
        
        if (!overlap) {
            create_room(r);
            rooms[room_count] = r;
            room_count++;
        }
        iteration_count++;
    }
    
    for (int i = 0; i < num_rooms - 1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}