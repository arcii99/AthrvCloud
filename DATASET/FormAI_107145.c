//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // map size
    int width = 50;
    int height = 20;

    // player starting position
    int playerX = 0;
    int playerY = 0;

    // create map with randomly generated walls
    char map[height][width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (rand() % 100 < 20) {
                map[y][x] = '#'; // wall
            }
            else {
                map[y][x] = '.'; // floor
            }
        }
    }

    // place player randomly on floor
    while (map[playerY][playerX] == '#') {
        playerX = rand() % width;
        playerY = rand() % height;
    }

    // game loop
    while (1) {
        // print map with player position
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (y == playerY && x == playerX) {
                    printf("@");
                }
                else {
                    printf("%c", map[y][x]);
                }
            }
            printf("\n");
        }

        // move player
        char input;
        printf("Move (wasd): ");
        scanf(" %c", &input);
        switch (input) {
            case 'w': // up
                if (playerY > 0 && map[playerY - 1][playerX] == '.') {
                    playerY--;
                }
                break;
            case 'a': // left
                if (playerX > 0 && map[playerY][playerX - 1] == '.') {
                    playerX--;
                }
                break;
            case 's': // down
                if (playerY < height - 1 && map[playerY + 1][playerX] == '.') {
                    playerY++;
                }
                break;
            case 'd': // right
                if (playerX < width - 1 && map[playerY][playerX + 1] == '.') {
                    playerX++;
                }
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}