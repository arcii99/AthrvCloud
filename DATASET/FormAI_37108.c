//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initializeMap(char spaceMap[10][10]);
void printMap(char spaceMap[10][10], int playerLocation[2]);
void moveUp(char spaceMap[10][10], int playerLocation[2]);
void moveDown(char spaceMap[10][10], int playerLocation[2]);
void moveLeft(char spaceMap[10][10], int playerLocation[2]);
void moveRight(char spaceMap[10][10], int playerLocation[2]);

// main function
int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize player location
    int playerLocation[2] = {0, 0};

    // initialize space map
    char spaceMap[10][10];
    initializeMap(spaceMap);

    // print initial map
    printMap(spaceMap, playerLocation);
    printf("\n\n");

    // player movement loop
    while (1) {
        // get user input
        printf("Enter movement direction: ");
        char direction;
        scanf(" %c", &direction);

        // move player
        if (direction == 'w') {
            moveUp(spaceMap, playerLocation);
        } else if (direction == 's') {
            moveDown(spaceMap, playerLocation);
        } else if (direction == 'a') {
            moveLeft(spaceMap, playerLocation);
        } else if (direction == 'd') {
            moveRight(spaceMap, playerLocation);
        } else {
            printf("Invalid input! Please enter w, s, a, or d.\n");
            continue;
        }

        // print updated map
        printMap(spaceMap, playerLocation);
        printf("\n\n");

        // check if player reached end location
        if (playerLocation[0] == 9 && playerLocation[1] == 9) {
            printf("Congratulations! You have reached the end.\n");
            break;
        }
    }

    return 0;
}

// function to initialize space map
void initializeMap(char spaceMap[10][10]) {
    // randomly generate map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (rand() % 2 == 0) {
                spaceMap[i][j] = '_';
            } else {
                spaceMap[i][j] = '|';
            }
        }   
    }

    // set start location
    spaceMap[0][0] = 'S';

    // set end location
    spaceMap[9][9] = 'E';
}

// function to print space map
void printMap(char spaceMap[10][10], int playerLocation[2]) {
    // print each row of map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // print player location
            if (i == playerLocation[0] && j == playerLocation[1]) {
                printf("P ");
            } else {
                printf("%c ", spaceMap[i][j]);
            }
        }
        printf("\n");
    }
}

// functions to handle player movement
void moveUp(char spaceMap[10][10], int playerLocation[2]) {
    // check if move is valid
    if (playerLocation[0] > 0 && spaceMap[playerLocation[0] - 1][playerLocation[1]] != '|') {
        // update player location
        playerLocation[0]--;

        // update map
        spaceMap[playerLocation[0] + 1][playerLocation[1]] = '_';
        spaceMap[playerLocation[0]][playerLocation[1]] = 'P';
    } else {
        printf("Invalid move!\n");
    }
}

void moveDown(char spaceMap[10][10], int playerLocation[2]) {
    // check if move is valid
    if (playerLocation[0] < 9 && spaceMap[playerLocation[0] + 1][playerLocation[1]] != '|') {
        // update player location
        playerLocation[0]++;

        // update map
        spaceMap[playerLocation[0] - 1][playerLocation[1]] = '_';
        spaceMap[playerLocation[0]][playerLocation[1]] = 'P';
    } else {
        printf("Invalid move!\n");
    }
}

void moveLeft(char spaceMap[10][10], int playerLocation[2]) {
    // check if move is valid
    if (playerLocation[1] > 0 && spaceMap[playerLocation[0]][playerLocation[1] - 1] != '_') {
        // update player location
        playerLocation[1]--;

        // update map
        spaceMap[playerLocation[0]][playerLocation[1] + 1] = '|';
        spaceMap[playerLocation[0]][playerLocation[1]] = 'P';
    } else {
        printf("Invalid move!\n");
    }
}

void moveRight(char spaceMap[10][10], int playerLocation[2]) {
    // check if move is valid
    if (playerLocation[1] < 9 && spaceMap[playerLocation[0]][playerLocation[1] + 1] != '_') {
        // update player location
        playerLocation[1]++;

        // update map
        spaceMap[playerLocation[0]][playerLocation[1] - 1] = '|';
        spaceMap[playerLocation[0]][playerLocation[1]] = 'P';
    } else {
        printf("Invalid move!\n");
    }
}