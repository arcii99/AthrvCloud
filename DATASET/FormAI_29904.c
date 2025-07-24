//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 1000
#define MAP_ROWS 20
#define MAP_COLS 50

typedef struct {
    int x;
    int y;
} Coords;

char Map[MAP_ROWS][MAP_COLS] = {
    "##################################################",
    "#                                                #",
    "#                       ##                       #",
    "#          #####################                 #",
    "#                       ##                       #",
    "#                      ####                      #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "#                                                #",
    "##################################################"
};

void printMap(Coords currPos) {
    system("clear");
    for (int i = 0; i < MAP_ROWS; i++) {
        for (int j = 0; j < MAP_COLS; j++) {
            if (currPos.x == j && currPos.y == i) {
                printf("@");
            } else {
                printf("%c", Map[i][j]);
            }
        }
        printf("\n");
    }
}

void navigate(Coords startPos, Coords endPos) {
    Coords currPos = startPos;

    while (currPos.x != endPos.x || currPos.y != endPos.y) {
        printMap(currPos);
        printf("Current Position: (%d,%d)\n", currPos.x, currPos.y);

        int moveX, moveY;

        do {
            printf("Enter movement in X direction (-1, 0, 1): ");
            scanf("%d", &moveX);
        } while (moveX < -1 || moveX > 1);
        currPos.x += moveX;

        do {
            printf("Enter movement in Y direction (-1, 0, 1): ");
            scanf("%d", &moveY);
        } while (moveY < -1 || moveY > 1);
        currPos.y += moveY;

        if (currPos.x < 0 || currPos.x >= MAP_COLS || currPos.y < 0 || currPos.y >= MAP_ROWS || Map[currPos.y][currPos.x] == '#') {
            printf("Invalid move! Please try again.\n");
            currPos.x -= moveX;
            currPos.y -= moveY;
        }
    }

    printf("You have reached your destination!\n");
}

int main() {
    Coords startPos = {5, 5};
    Coords endPos = {45, 15};
    navigate(startPos, endPos);
    return 0;
}