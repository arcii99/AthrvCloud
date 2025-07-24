//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>

// Function to move disk from the source tower to the target tower
void moveDisk(int disk, char source, char target) {
    printf("Move disk %d from %c to %c\n", disk, source, target);
}

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int disk, char source, char auxiliary, char target) {
    if (disk == 1) {
        moveDisk(disk, source, target);
        return;
    }
    towerOfHanoi(disk - 1, source, target, auxiliary);
    moveDisk(disk, source, target);
    towerOfHanoi(disk - 1, auxiliary, source, target);
}

int main() {
    int numberOfDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numberOfDisks);

    towerOfHanoi(numberOfDisks, 'A', 'B', 'C');

    return 0;
}