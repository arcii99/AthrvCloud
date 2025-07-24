//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char map[HEIGHT][WIDTH];

void generateMap() {
    int i, j;

    // Fill the map with empty spaces
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            map[i][j] = ' ';
        }
    }

    // Randomly place walls
    for (i = 1; i < HEIGHT - 1; i++) {
        for (j = 1; j < WIDTH - 1; j++) {
            if (rand() % 100 < 30) {
                map[i][j] = '#';
            }
        }
    }

    // Place the player in a random location
    int x, y;
    do {
        x = rand() % (WIDTH - 2) + 1;
        y = rand() % (HEIGHT - 2) + 1;
    } while (map[y][x] != ' ');
    map[y][x] = '@';
}

void printMap() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void playerMove(int dx, int dy) {
    int px, py;
    for (py = 0; py < HEIGHT; py++) {
        for (px = 0; px < WIDTH; px++) {
            if (map[py][px] == '@') {
                if (map[py + dy][px + dx] == ' ') {
                    map[py][px] = ' ';
                    map[py + dy][px + dx] = '@';
                }
                return;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    generateMap();
    printMap();

    char input;
    do {
        scanf(" %c", &input);
        switch (input) {
        case 'w':
            playerMove(0, -1);
            break;
        case 'a':
            playerMove(-1, 0);
            break;
        case 's':
            playerMove(0, 1);
            break;
        case 'd':
            playerMove(1, 0);
            break;
        default:
            break;
        }
        printMap();
    } while (input != 'q');

    return 0;
}