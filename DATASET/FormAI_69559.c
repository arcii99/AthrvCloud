//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROOMS 1
#define MAX_ROOMS 10
#define MIN_GHOSTS 1
#define MAX_GHOSTS 5

int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void printGhost(int num) {
    printf("Boo! Ghost #%d appears!\n", num);
}

void simulateHouse(int numRooms) {
    int numGhosts = randomInt(MIN_GHOSTS, MAX_GHOSTS);
    int i;

    printf("Welcome to the haunted house simulator!\n");
    printf("You enter a house with %d rooms.\n", numRooms);
    printf("You feel a chill down your spine as you enter the first room...\n");

    for (i = 1; i <= numGhosts; i++) {
        int roomNum = randomInt(1, numRooms);
        printGhost(i);
        printf("Ghost #%d appears in room #%d!\n", i, roomNum);
    }

    printf("You have survived the haunted house!\n");
}

int main() {
    srand(time(0));
    int numRooms = randomInt(MIN_ROOMS, MAX_ROOMS);

    simulateHouse(numRooms);

    return 0;
}