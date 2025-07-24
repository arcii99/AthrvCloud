//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point;

char map[20][20];
point playerPos;
point targetPos;

void generateMap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            map[i][j] = rand() % 2 == 0 ? '#' : '.';
        }
    }
}

void movePlayer() {
    char input;
    printf("Enter a direction to move (w, a, s, d): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            if (playerPos.y != 0 && map[playerPos.y - 1][playerPos.x] != '#') {
                playerPos.y--;
            }
            break;
        case 'a':
            if (playerPos.x != 0 && map[playerPos.y][playerPos.x - 1] != '#') {
                playerPos.x--;
            }
            break;
        case 's':
            if (playerPos.y != 19 && map[playerPos.y + 1][playerPos.x] != '#') {
                playerPos.y++;
            }
            break;
        case 'd':
            if (playerPos.x != 19 && map[playerPos.y][playerPos.x + 1] != '#') {
                playerPos.x++;
            }
            break;
        default:
            printf("Invalid input!\n");
            break;
    }
}

void printMap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == playerPos.y && j == playerPos.x) printf("@");
            else if (i == targetPos.y && j == targetPos.x) printf("$");
            else printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void main() {
    srand(time(NULL));
    generateMap();
    playerPos.x = rand() % 20;
    playerPos.y = rand() % 20;
    targetPos.x = rand() % 20;
    targetPos.y = rand() % 20;
    while (map[playerPos.y][playerPos.x] == '#' || map[targetPos.y][targetPos.x] == '#') {
        // Regenerate playerPos and targetPos until they're both on a non-wall tile
        playerPos.x = rand() % 20;
        playerPos.y = rand() % 20;
        targetPos.x = rand() % 20;
        targetPos.y = rand() % 20;
    }
    printf("You are '@'. Your goal is to reach the '$'.\n");
    while (playerPos.x != targetPos.x || playerPos.y != targetPos.y) {
        printMap();
        movePlayer();
    }
    printf("Congratulations, you won!\n");
}