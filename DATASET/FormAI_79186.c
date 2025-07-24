//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20

typedef struct {
    int x;
    int y;
} coordinates;

void generateMap(char map[MAP_SIZE][MAP_SIZE]);
void initPlayer(coordinates *pCoord);
void printMap(char map[MAP_SIZE][MAP_SIZE], coordinates playerCoord);

int main()
{
    char map[MAP_SIZE][MAP_SIZE];
    coordinates playerCoord;
    int gameOver = 0;
    
    srand(time(NULL));
    
    generateMap(map);
    initPlayer(&playerCoord);
    
    printf("Welcome to the game!\n");
    printf("Use arrow keys to move around the map.\n");
    printf("Try to reach the exit marked by 'X'.\n\n");
    
    while (!gameOver) {
        printMap(map, playerCoord);
        
        char input;
        scanf(" %c", &input);
        
        switch (input) {
            case 'w':
            case 'W':
                if (playerCoord.y > 0) {
                    playerCoord.y--;
                }
                break;
            case 'a':
            case 'A':
                if (playerCoord.x > 0) {
                    playerCoord.x--;
                }
                break;
            case 's':
            case 'S':
                if (playerCoord.y < MAP_SIZE - 1) {
                    playerCoord.y++;
                }
                break;
            case 'd':
            case 'D':
                if (playerCoord.x < MAP_SIZE - 1) {
                    playerCoord.x++;
                }
                break;
            case 'q':
            case 'Q':
                printf("Thanks for playing!\n");
                gameOver = 1;
                break;
            default:
                break;
        }
        
        if (map[playerCoord.y][playerCoord.x] == 'X') {
            printf("Congratulations, you have won!\n");
            gameOver = 1;
        }
    }
    
    return 0;
}

void generateMap(char map[MAP_SIZE][MAP_SIZE])
{
    int i, j;
    
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (rand() % 3 == 0) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
    
    map[rand() % MAP_SIZE][rand() % MAP_SIZE] = 'X';
}

void initPlayer(coordinates *pCoord)
{
    pCoord->x = rand() % MAP_SIZE;
    pCoord->y = rand() % MAP_SIZE;
}

void printMap(char map[MAP_SIZE][MAP_SIZE], coordinates playerCoord)
{
    int i, j;
    
    system("clear");
    
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == playerCoord.y && j == playerCoord.x) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}