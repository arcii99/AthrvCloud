//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/*
This program solves the Tower of Hanoi problem for any number of disks and any number of towers.
The problem involves moving a stack of n disks of different sizes from the first tower to the last tower, using a middle tower as an intermediary.
The solution uses recursion to solve the problem, moving smaller stacks of disks one at a time until the entire stack has been moved to the last tower.
*/

void towerOfHanoi(int n, int source, int middle[], int destination) {
    if (n == 0) {
        return;
    }

    // Move smaller stack of n-1 disks from source to middle tower
    towerOfHanoi(n-1, source, destination, middle);

    // Move the largest disk from the source tower to destination tower
    printf("Move disk %d from Tower %d to Tower %d\n", n, source, destination);

    // Move smaller stack of n-1 disks from the middle tower to destination tower
    towerOfHanoi(n-1, middle, source, destination);
}

int main() {
    int numDisks, numTowers;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    printf("Enter the number of towers: ");
    scanf("%d", &numTowers);

    if (numDisks <= 0 || numTowers <= 2) {
        printf("Invalid input!\n");
        return 1;
    }

    int *middleTowers = malloc(sizeof(int) * (numTowers - 2));

    printf("Tower of Hanoi solution for %d disks and %d towers:\n", numDisks, numTowers);
    towerOfHanoi(numDisks, 1, middleTowers, numTowers);

    free(middleTowers);
    return 0;
}