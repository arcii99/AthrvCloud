//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS];
int playerRow, playerCol;

void initMap();
void printMap();
void move(char input);

int main() {
    srand(time(NULL)); // seed for random function
    initMap();
    printMap();
    while (1) {
        printf("Enter W, A, S, or D to move: ");
        char input = getchar();
        getchar(); // needed to clear buffer
        move(input);
        printMap();
        if (map[playerRow][playerCol] == 'X') {
            printf("You escaped the haunted house!\n");
            break;
        }
    }

    return 0;
}

void initMap() {
    // initialize map with walls and door
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                map[i][j] = '#'; // wall
            } else if (i == ROWS-2 && j == COLS/2) {
                map[i][j] = 'X'; // escape door
            } else {
                map[i][j] = ' '; // empty space
            }
        }
    }

    // randomly place obstacles and items
    for (int i = 0; i < 3; i++) {
        int randRow = rand() % (ROWS-2) + 1; // exclude borders
        int randCol = rand() % (COLS-2) + 1;
        if (map[randRow][randCol] == ' ') {
            map[randRow][randCol] = 'O'; // obstacle
        } else {
            i--; // try again
        }
    }

    // place player at starting position
    playerRow = ROWS-2;
    playerCol = COLS/2;
    map[playerRow][playerCol] = '@';
}

void printMap() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move(char input) {
    int newRow = playerRow, newCol = playerCol;

    // update new row and column based on input
    switch (input) {
        case 'W': newRow--; break;
        case 'A': newCol--; break;
        case 'S': newRow++; break;
        case 'D': newCol++; break;
    }

    // check if new position is valid
    if (map[newRow][newCol] == '#' || newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
        printf("Invalid move!\n");
        return;
    }

    // move player to new position
    map[playerRow][playerCol] = ' ';
    playerRow = newRow;
    playerCol = newCol;
    map[playerRow][playerCol] = '@';

    // check if player runs into obstacle
    if (map[playerRow][playerCol] == 'O') {
        printf("You ran into an obstacle!\n");
        initMap(); // restart game
    }
}