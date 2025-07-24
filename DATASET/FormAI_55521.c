//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>

void moveDisks(int, char, char, char);

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    printf("Steps to solve the problem:\n");
    moveDisks(numDisks, 'A', 'C', 'B');

    return 0;
}

void moveDisks(int disks, char source, char destination, char auxiliary) {
    if (disks == 0) {
        // Base case: no disks to move
        return;
    }

    // Move disks-1 from source to auxiliary using destination as auxiliary peg
    moveDisks(disks-1, source, auxiliary, destination);

    // Move the nth disk from source to destination
    printf("Move disk %d from peg %c to peg %c.\n", disks, source, destination);

    // Move the disks from auxiliary to destination using source as auxiliary peg
    moveDisks(disks-1, auxiliary, destination, source);
}