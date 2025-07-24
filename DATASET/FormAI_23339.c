//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char map[HEIGHT][WIDTH];

int playerX, playerY;

void initMap() {
    int i, j;
    
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void placePlayer() {
    int x, y;
    
    do {
        x = rand() % (WIDTH-2) + 1;
        y = rand() % (HEIGHT-2) + 1;
    } while (map[y][x] != '.');
    
    playerX = x;
    playerY = y;
    map[playerY][playerX] = '@';
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

void generateMap() {
    int i, j, n;
    srand(time(NULL));
    
    for (n = 0; n < 10; n++) {
        int x = rand() % (WIDTH-2) + 1;
        int y = rand() % (HEIGHT-2) + 1;
        for (i = y-1; i <= y+1; i++) {
            for (j = x-1; j <= x+1; j++) {
                if (map[i][j] == '.') {
                    map[i][j] = '#';
                }
            }
        }           
    }   
}

void movePlayer(char direction) {
    int newX = playerX, newY = playerY;
    
    if (direction == 'w' && map[playerY-1][playerX] == '.') {
        newY--;
    } else if (direction == 's' && map[playerY+1][playerX] == '.') {
        newY++;
    } else if (direction == 'a' && map[playerY][playerX-1] == '.') {
        newX--;
    } else if (direction == 'd' && map[playerY][playerX+1] == '.') {
        newX++;
    }
    
    if (newX != playerX || newY != playerY) {
        map[playerY][playerX] = '.';
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = '@';
    }
}

int main() {
    initMap();
    generateMap();
    placePlayer();
    char input;
    
    do {
        printMap();
        printf("Enter move (WASD) or Q to quit: ");
        scanf(" %c", &input);
        movePlayer(input);
    } while (input != 'q');
    
    return 0;
}