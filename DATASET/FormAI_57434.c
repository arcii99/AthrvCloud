//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int count = 0; // global variable to count number of moves made

// function to move disk from one rod to another
void moveDisk(int fromRod, int toRod) {
    printf("Move disk from rod %d to rod %d\n", fromRod, toRod);
    count++;
}

// recursive function to solve Tower of Hanoi problem
void solveHanoi(int n, int fromRod, int toRod, int auxRod) {
    if(n == 1) {
        moveDisk(fromRod, toRod);
        return;
    }
    solveHanoi(n-1, fromRod, auxRod, toRod);
    moveDisk(fromRod, toRod);
    solveHanoi(n-1, auxRod, toRod, fromRod);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // safety check for input
    if(numDisks <= 0) {
        printf("Invalid input. Number of disks should be greater than 0.\n");
        return 1;
    }

    // start the game
    printf("Starting configuration: \n");
    printf("Rod 1: ");
    for(int i=numDisks; i>=1; i--) {
        printf("%d ", i);
    }
    printf("\nRod 2: \nRod 3: \n\n");

    // finish the game
    printf("Moves:\n");
    solveHanoi(numDisks, 1, 3, 2);

    printf("\nTotal number of moves: %d\n", count);

    return 0;
}