//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEIGHT 30
#define MAX_WIDTH 80
#define MAX_ROOMS 10
#define MIN_ROOM_HEIGHT 5
#define MIN_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 15
#define MAX_ROOM_WIDTH 20

enum TileType {
    Wall,
    Floor
};

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int height;
    int width;
} Room;

typedef struct {
    enum TileType type;
    int visited;
} Tile;

void generateLevel(Tile level[MAX_HEIGHT][MAX_WIDTH], Room rooms[], int roomCount) {
    int i, j;

    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            level[i][j].type = Wall;
            level[i][j].visited = 0;
        }
    }

    for (i = 0; i < roomCount; i++) {
        Room r = rooms[i];
        int x, y;

        for (y = r.y; y < r.y + r.height; y++) {
            for (x = r.x; x < r.x + r.width; x++) {
                level[y][x].type = Floor;
            }
        }
    }

    for (i = 0; i < roomCount - 1; i++) {
        Room r1 = rooms[i];
        Room r2 = rooms[i + 1];

        Point p1 = {r1.x + r1.width / 2, r1.y + r1.height / 2};
        Point p2 = {r2.x + r2.width / 2, r2.y + r2.height / 2};

        while (p1.x != p2.x || p1.y != p2.y) {
            if (p1.x < p2.x) {
                p1.x++;
                level[p1.y][p1.x].type = Floor;
            } else if (p1.x > p2.x) {
                p1.x--;
                level[p1.y][p1.x].type = Floor;
            } else if (p1.y < p2.y) {
                p1.y++;
                level[p1.y][p1.x].type = Floor;
            } else if (p1.y > p2.y) {
                p1.y--;
                level[p1.y][p1.x].type = Floor;
            }
        }
    }
}

void printLevel(Tile level[MAX_HEIGHT][MAX_WIDTH]) {
    int i, j;

    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            if (level[i][j].type == Wall) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int i;
    Room rooms[MAX_ROOMS];
    int roomCount = rand() % MAX_ROOMS + 1;

    for (i = 0; i < roomCount; i++) {
        Room r;

        r.width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH) + MIN_ROOM_WIDTH;
        r.height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT) + MIN_ROOM_HEIGHT;
        r.x = rand() % (MAX_WIDTH - r.width - 1) + 1;
        r.y = rand() % (MAX_HEIGHT - r.height - 1) + 1;

        rooms[i] = r;
    }

    Tile level[MAX_HEIGHT][MAX_WIDTH];
    generateLevel(level, rooms, roomCount);
    printLevel(level);

    return 0;
}