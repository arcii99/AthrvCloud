//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COLUMN 50

char house[ROW][COLUMN];
int playerRow, playerColumn;
int ghostRow, ghostColumn;
int gameStatus = 1, winMessage = 0;

void generateHouse();
void printHouse();
void movePlayer();
void moveGhost();

int main() {
    srand(time(0));
    generateHouse();
    playerRow = ROW-2;
    playerColumn = COLUMN/2;
    ghostRow = 1;
    ghostColumn = rand() % (COLUMN-2) + 1;

    while(gameStatus) {
        printHouse();
        movePlayer();
        moveGhost();
        if(playerRow == ghostRow && playerColumn == ghostColumn) {
            gameStatus = 0;
        }
        if(playerRow == 1) {
            winMessage = 1;
            gameStatus = 0;
        }
    }
    printHouse();
    if(winMessage) {
        printf("\nCongratulations! You made it out of the haunted house!\n");
    }
    else {
        printf("\nGame over! You were caught by the ghost...\n");
    }

    return 0;
}

void generateHouse() {
    int i, j;

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COLUMN; j++) {
            if(i == 0 || i == ROW-1 || j == 0 || j == COLUMN-1) {
                house[i][j] = '#';
            }
            else {
                house[i][j] = ' ';
            }
        }
    }
    house[1][1] = 'G';
    house[ROW-2][COLUMN/2] = 'P';
}

void printHouse() {
    int i, j;
    system("clear");

    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COLUMN; j++) {
            printf("%c", house[i][j]);
        }
        printf("\n");
    }
}

void movePlayer() {
    char input;

    printf("Use the arrow keys to move. Press 'q' to quit.\n");
    input = getchar();

    switch(input) {
        case 'q':
            gameStatus = 0;
            break;
        case '\033':
            getchar();
            input = getchar();
            switch(input) {
                case 'A':
                    if(house[playerRow-1][playerColumn] == ' ') {
                        house[playerRow][playerColumn] = ' ';
                        playerRow--;
                        house[playerRow][playerColumn] = 'P';
                    }
                    break;
                case 'B':
                    if(house[playerRow+1][playerColumn] == ' ') {
                        house[playerRow][playerColumn] = ' ';
                        playerRow++;
                        house[playerRow][playerColumn] = 'P';
                    }
                    break;
                case 'C':
                    if(house[playerRow][playerColumn+1] == ' ') {
                        house[playerRow][playerColumn] = ' ';
                        playerColumn++;
                        house[playerRow][playerColumn] = 'P';
                    }
                    break;
                case 'D':
                    if(house[playerRow][playerColumn-1] == ' ') {
                        house[playerRow][playerColumn] = ' ';
                        playerColumn--;
                        house[playerRow][playerColumn] = 'P';
                    }
                    break;
            }
            break;
    }
}

void moveGhost() {
    int direction;

    direction = rand() % 4;

    switch(direction) {
        case 0:
            if(house[ghostRow-1][ghostColumn] == ' ') {
                house[ghostRow][ghostColumn] = ' ';
                ghostRow--;
                house[ghostRow][ghostColumn] = 'G';
            }
            break;
        case 1:
            if(house[ghostRow+1][ghostColumn] == ' ') {
                house[ghostRow][ghostColumn] = ' ';
                ghostRow++;
                house[ghostRow][ghostColumn] = 'G';
            }
            break;
        case 2:
            if(house[ghostRow][ghostColumn+1] == ' ') {
                house[ghostRow][ghostColumn] = ' ';
                ghostColumn++;
                house[ghostRow][ghostColumn] = 'G';
            }
            break;
        case 3:
            if(house[ghostRow][ghostColumn-1] == ' ') {
                house[ghostRow][ghostColumn] = ' ';
                ghostColumn--;
                house[ghostRow][ghostColumn] = 'G';
            }
            break;
    }
}