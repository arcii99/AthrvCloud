//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the shape of the towers in the current move
void shapeShift(int n, int source[], int target[], int spare[]) {
    if (n % 2 == 0) {
        // For even n, the shape shifts by exchanging the target and spare towers
        int temp = *target;
        *target = *spare;
        *spare = temp;
    } else {
        // For odd n, the shape shifts by exchanging the source and target towers
        int temp = *source;
        *source = *target;
        *target = temp;
    }
}

// Function to perform a Tower of Hanoi move
void moveDisk(int from[], int to[]) {
    int disk = from[--from[0]];
    to[++to[0]] = disk;
    printf("Move disk %d from peg %d to peg %d\n", disk, from - &from[0], to - &to[0]);
}

// Function to solve the Tower of Hanoi puzzle with n disks
void towerOfHanoi(int n, int source[], int target[], int spare[]) {
    for (int i = n; i >= 1; i--) {
        // Consider the problem of moving i disks from source to target using spare as the spare tower
        // We have to perform (2^i - 1) moves to solve this sub-problem
        int numOfMoves = (1 << i) - 1;

        // Shift the shape of the towers according to the current move
        shapeShift(i, source, target, spare);

        // Perform the moves to solve this sub-problem
        for (int j = 0; j < numOfMoves; j++) {
            if (j % 3 == 0) {
                moveDisk(source, target);
            } else if (j % 3 == 1) {
                moveDisk(source, spare);
            } else {
                moveDisk(spare, target);
            }
        }
    }
}

int main() {
    int n = 4; // number of disks
    int source[n + 1], target[n + 1], spare[n + 1];
    memset(source, 0, sizeof(source));
    memset(target, 0, sizeof(target));
    memset(spare, 0, sizeof(spare));
    source[0] = target[0] = spare[0] = n;

    printf("Starting tower configuration:\n");
    for (int i = n; i >= 1; i--) {
        source[++source[0]] = i;
    }
    printf("Source: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", source[i]);
    }
    printf("\nTarget: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", target[i]);
    }
    printf("\nSpare: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", spare[i]);
    }
    printf("\n");

    towerOfHanoi(n, source, target, spare);

    printf("Final tower configuration:\n");
    printf("Source: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", source[i]);
    }
    printf("\nTarget: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", target[i]);
    }
    printf("\nSpare: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", spare[i]);
    }
    printf("\n");
    return 0;
}