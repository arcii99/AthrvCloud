//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define WIDTH 20
#define HEIGHT 10
#define MAX_LEVEL 5
#define MAX_ROOMS 6

// struct to hold room properties
typedef struct {
    int x,y,w,h;
} Room;

// function to randomly generate valid room
Room generateRoom() {
    Room r;
    r.w = (rand() % 5) + 4;
    r.h = (rand() % 5) + 4;
    r.x = rand() % (WIDTH - r.w - 1) + 1;
    r.y = rand() % (HEIGHT - r.h - 1) + 1;
    return r;
}

// function to check if two rooms intersect
int doesRoomIntersect(Room r1, Room r2) {
    if (r1.x > r2.x + r2.w || r1.x + r1.w < r2.x ||
        r1.y > r2.y + r2.h || r1.y + r1.h < r2.y) {
        return 0;
    }
    return 1;
}

// function to randomly generate level layout
void generateLevel(char level[][WIDTH]) {
    // initialize everything to wall
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            level[i][j] = '#';
        }
    }

    // randomly generate rooms
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room r = generateRoom();
        int intersects = 0;
        for (int j = 0; j < i; j++) {
            if (doesRoomIntersect(r, rooms[j])) {
                intersects = 1;
                break;
            }
        }
        if (!intersects) {
            rooms[i] = r;
            for (int y = r.y + 1; y < r.y + r.h - 1; y++) {
                for (int x = r.x + 1; x < r.x + r.w - 1; x++) {
                    level[y][x] = '.';
                }
            }
        }
    }

    // randomly connect rooms with corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].w / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].h / 2;
        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            }
            if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }
            level[y1][x1] = '.';
        }
    }
}

int main() {
    srand(time(NULL));

    for (int i = 1; i <= MAX_LEVEL; i++) {
        char level[HEIGHT][WIDTH];
        generateLevel(level);

        // print level
        printf("LEVEL %d\n", i);
        for (int j = 0; j < HEIGHT; j++) {
            for (int k = 0; k < WIDTH; k++) {
                printf("%c", level[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}