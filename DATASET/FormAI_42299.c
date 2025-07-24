//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

char map[WIDTH][HEIGHT];
int player_x, player_y;

void generateMap() {
    int i, j;

    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            if(rand() % 100 > 80) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = '.';
            }
        }
    }

    player_x = rand() % WIDTH;
    player_y = rand() % HEIGHT;
    map[player_x][player_y] = '@';
}

void printMap() {
    int i, j;

    for(j = 0; j < HEIGHT; j++) {
        for(i = 0; i < WIDTH; i++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    int new_x = player_x + dx;
    int new_y = player_y + dy;

    if(new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT && map[new_x][new_y] != '#') {
        map[player_x][player_y] = '.';
        player_x = new_x;
        player_y = new_y;
        map[player_x][player_y] = '@';
    }
}

int main() {
    srand(time(NULL));

    generateMap();
    printMap();

    char input;

    while(input != 'q') {
        printf("Enter a direction (wasd) or q to quit: ");
        scanf(" %c", &input);

        switch(input) {
            case 'w':
                move(0, -1);
                break;
            case 'a':
                move(-1, 0);
                break;
            case 's':
                move(0, 1);
                break;
            case 'd':
                move(1, 0);
                break;
        }

        printMap();
    }

    return 0;
}