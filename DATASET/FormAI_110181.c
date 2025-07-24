//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_ROBOT_NUM 5

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int id;
    Position pos;
} Robot;

void printMap(Robot robots[], int robotNum, Position treasures[], int treasureNum) {
    char map[MAP_SIZE][MAP_SIZE] = {' '};
    int i, j;

    for (i = 0; i < robotNum; i++) {
        map[robots[i].pos.x][robots[i].pos.y] = 'R';
    }

    for (i = 0; i < treasureNum; i++) {
        map[treasures[i].x][treasures[i].y] = 'T';
    }

    for (i = 0; i < MAP_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");

    for (i = 0; i < MAP_SIZE; i++) {
        printf("|");
        for (j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("|\n");
    }

    for (i = 0; i < MAP_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    int i, j, robotNum, treasureNum;
    Robot robots[MAX_ROBOT_NUM];
    Position treasures[MAX_ROBOT_NUM];
    srand(time(NULL));
    
    robotNum = 3 + rand() % 3;
    for (i = 0; i < robotNum; i++) {
        robots[i].id = i;
        robots[i].pos.x = rand() % MAP_SIZE;
        robots[i].pos.y = rand() % MAP_SIZE;
    }

    treasureNum = 3 + rand() % 3;
    for (i = 0; i < treasureNum; i++) {
        treasures[i].x = rand() % MAP_SIZE;
        treasures[i].y = rand() % MAP_SIZE;
    }

    printMap(robots, robotNum, treasures, treasureNum);

    char command;

    while (1) {
        for (i = 0; i < robotNum; i++) {
            printf("Robot %d, input direction: ", i);
            scanf(" %c", &command);
            switch (command) {
                case 'U':
                    if (robots[i].pos.x > 0) {
                        robots[i].pos.x--;
                    }
                    break;
                case 'D':
                    if (robots[i].pos.x < MAP_SIZE - 1) {
                        robots[i].pos.x++;
                    }
                    break;
                case 'L':
                    if (robots[i].pos.y > 0) {
                        robots[i].pos.y--;
                    }
                    break;
                case 'R':
                    if (robots[i].pos.y < MAP_SIZE - 1) {
                        robots[i].pos.y++;
                    }
                    break;
                default:
                    printf("Invalid input!\n");
                    break;
            }

            for (j = 0; j < treasureNum; j++) {
                if (robots[i].pos.x == treasures[j].x && robots[i].pos.y == treasures[j].y) {
                    printf("Robot %d found treasure %d!\n", i, j);
                }
            }

            printMap(robots, robotNum, treasures, treasureNum);
        }
    }

    return 0;
}