//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isGhostAppeared(int probability) {
    return rand() % 100 < probability;
}

void visitRoom(int roomNumber) {
    printf("You enter room %d...\n", roomNumber);
    if (roomNumber == 10) {
        printf("You found the exit!\n");
        return;
    }
    if (isGhostAppeared(10)) {
        printf("A ghost appeared and scared you away!\n");
        return;
    }
    visitRoom(roomNumber + 1);
}

int main() {
    srand(time(NULL));
    printf("Welcome to Haunted House Simulator!\n");
    printf("You are now entering the haunted house...\n");
    visitRoom(1);
    printf("You have successfully exited the house. Congratulations!\n");
    return 0; 
}