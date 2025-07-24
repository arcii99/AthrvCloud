//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 10
#define MAX_COL 20

void generateMap(char map[][MAX_COL]);
void printMap(char map[][MAX_COL]);
int movePlayer(char map[][MAX_COL], int *playerRow, int *playerCol);

int main() {
    srand(time(NULL));
    char map[MAX_ROW][MAX_COL];
    int playerRow = 0, playerCol = 0;
    generateMap(map);
    printMap(map);
    while (1) {
        int result = movePlayer(map, &playerRow, &playerCol);
        if (result == 0) {
            printf("You have found the exit! Congratulations!\n");
            break;
        } else if (result == -1) {
            printf("You have been eaten by a grue. Game over.\n");
            break;
        }
        printMap(map);
    }
    return 0;
}

void generateMap(char map[][MAX_COL]) {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            int randNum = rand() % 100;
            if (randNum < 10) { // 10% chance of obstacle
                map[i][j] = '#';
            } else if (randNum < 20) { // 10% chance of power-up
                map[i][j] = '+';
            } else { // 80% chance of empty space
                map[i][j] = ' ';
            }
        }
    }
    map[MAX_ROW - 1][MAX_COL - 1] = '>';
}

void printMap(char map[][MAX_COL]) {
    int i, j;
    printf(" ");
    for (i = 0; i < MAX_COL; i++) {
        printf("_");
    }
    printf("\n");
    for (i = 0; i < MAX_ROW; i++) {
        printf("|");
        for (j = 0; j < MAX_COL; j++) {
            printf("%c", map[i][j]);
        }
        printf("|\n");
    }
    printf(" ");
    for (i = 0; i < MAX_COL; i++) {
        printf("-");
    }
    printf("\n");
}

int movePlayer(char map[][MAX_COL], int *playerRow, int *playerCol) {
    char input;
    printf("Enter a direction (wasd): ");
    scanf(" %c", &input);
    int newRow = *playerRow, newCol = *playerCol;
    switch (input) {
        case 'w':
            newRow--;
            break;
        case 'a':
            newCol--;
            break;
        case 's':
            newRow++;
            break;
        case 'd':
            newCol++;
            break;
        default:
            printf("Invalid input.\n");
            return movePlayer(map, playerRow, playerCol);
    }
    if (newRow < 0 || newRow >= MAX_ROW || newCol < 0 || newCol >= MAX_COL) {
        printf("You hit a wall.\n");
        return 1;
    } else if (map[newRow][newCol] == '#') {
        printf("Ouch! You hit an obstacle.\n");
        return 1;
    } else if (map[newRow][newCol] == '+') {
        printf("You found a power-up! Your vision expands...\n");
        map[newRow][newCol] = ' ';
        if (*playerCol > 0 && map[*playerRow][*playerCol - 1] != '#') {
            map[*playerRow][*playerCol - 1] = ' ';
        }
        if (*playerRow > 0 && map[*playerRow - 1][*playerCol] != '#') {
            map[*playerRow - 1][*playerCol] = ' ';
        }
        if (*playerRow < MAX_ROW - 1 && map[*playerRow + 1][*playerCol] != '#') {
            map[*playerRow + 1][*playerCol] = ' ';
        }
        if (*playerCol < MAX_COL - 1 && map[*playerRow][*playerCol + 1] != '#') {
            map[*playerRow][*playerCol + 1] = ' ';
        }
    } else if (map[newRow][newCol] == '>') {
        return 0;
    }
    map[*playerRow][*playerCol] = ' ';
    map[newRow][newCol] = '@';
    *playerRow = newRow;
    *playerCol = newCol;
    return 1;
}