//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 8

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef struct {
    int x;
    int y;
} Point;

char map[HEIGHT][WIDTH];
Room rooms[MAX_ROOMS];
int num_rooms = 0;

void init_map() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void draw_map() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }
}

int is_point_in_room(Room room, Point point) {
    return (point.x >= room.x && point.x < room.x + room.width &&
            point.y >= room.y && point.y < room.y + room.height);
}

void add_room(int x, int y, int width, int height) {
    rooms[num_rooms].x = x;
    rooms[num_rooms].y = y;
    rooms[num_rooms].width = width;
    rooms[num_rooms].height = height;

    int i, j;
    for (i = y; i < y + height; i++) {
        for (j = x; j < x + width; j++) {
            map[i][j] = '.';
        }
    }

    num_rooms++;
}

int is_overlap(Room a, Room b) {
    int a_right = a.x + a.width;
    int a_bottom = a.y + a.height;
    int b_right = b.x + b.width;
    int b_bottom = b.y + b.height;

    if (a_right <= b.x || a.x >= b_right) {
        return 0;
    }

    if (a_bottom <= b.y || a.y >= b_bottom) {
        return 0;
    }

    return 1;
}

int collides_with_other_rooms(int x, int y, int width, int height) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (is_overlap((Room){x, y, width, height}, rooms[i])) {
            return 1;
        }
    }
    return 0;
}

void add_rooms_recursive(int min_x, int min_y, int max_x, int max_y) {
    if (num_rooms == MAX_ROOMS || max_x - min_x <= MAX_ROOM_WIDTH * 2 || max_y - min_y <= MAX_ROOM_HEIGHT * 2) {
        return;
    }

    int x = min_x + MAX_ROOM_WIDTH + rand() % (max_x - min_x - MAX_ROOM_WIDTH * 2);
    int y = min_y + MAX_ROOM_HEIGHT + rand() % (max_y - min_y - MAX_ROOM_HEIGHT * 2);
    int width = 4 + rand() % (MAX_ROOM_WIDTH - 3);
    int height = 4 + rand() % (MAX_ROOM_HEIGHT - 3);

    if (!collides_with_other_rooms(x, y, width, height)) {
        add_room(x, y, width, height);
    }

    add_rooms_recursive(min_x, min_y, x - 1, max_y);
    add_rooms_recursive(x + width, min_y, max_x, max_y);
    add_rooms_recursive(x, min_y, x + width - 1, y - 1);
    add_rooms_recursive(x, y + height, x + width - 1, max_y);
}

int main(int argc, char **argv) {
    srand(time(NULL));

    init_map();
    add_rooms_recursive(0, 0, WIDTH, HEIGHT);
    draw_map();

    return 0;
}