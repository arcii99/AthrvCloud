//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_ROOMS 6

typedef struct {
    int x, y, w, h;
} Room;

char dungeon[HEIGHT][WIDTH];

void create_room(Room r) {
    for (int y = r.y; y < r.y + r.h; y++) {
        for (int x = r.x; x < r.x + r.w; x++) {
            dungeon[y][x] = '.';
        }
    }
}

void create_h_tunnel(int x1, int x2, int y) {
    for (int x = x1; x < x2 + 1; x++) {
        dungeon[y][x] = '.';
    }
}

void create_v_tunnel(int y1, int y2, int x) {
    for (int y = y1; y < y2 + 1; y++) {
        dungeon[y][x] = '.';
    }
}

Room create_random_room() {
    Room r;
    r.w = rand() % 6 + 4;
    r.h = rand() % 4 + 3;
    r.x = rand() % (WIDTH - r.w - 1) + 1;
    r.y = rand() % (HEIGHT - r.h - 1) + 1;
    return r;
}

void connect_rooms(Room r1, Room r2) {
    int x1 = r1.x + rand() % r1.w;
    int x2 = r2.x + rand() % r2.w;
    int y1 = r1.y + rand() % r1.h;
    int y2 = r2.y + rand() % r2.h;

    if (rand() % 2) {
        create_h_tunnel(x1, x2, y1);
        create_v_tunnel(y1, y2, x2);
    } else {
        create_v_tunnel(y1, y2, x1);
        create_h_tunnel(x1, x2, y2);
    }
}

void generate_dungeon() {
    int num_rooms = 0;
    Room rooms[MAX_ROOMS];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon[y][x] = '#';
        }
    }

    while (num_rooms < MAX_ROOMS) {
        Room r = create_random_room();

        int overlaps = 0;
        for (int i = 0; i < num_rooms; i++) {
            Room r2 = rooms[i];
            if (r.x < r2.x + r2.w &&
                r.x + r.w > r2.x &&
                r.y < r2.y + r2.h &&
                r.y + r.h > r2.y) {
                overlaps = 1;
                break;
            }
        }

        if (!overlaps) {
            rooms[num_rooms] = r;
            create_room(r);
            num_rooms++;
        }
    }

    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        connect_rooms(rooms[i], rooms[i + 1]);
    }

}

void print_dungeon() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", dungeon[y][x]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_dungeon();
    print_dungeon();
    return 0;
}