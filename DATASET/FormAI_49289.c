//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>

int stepCount = 0; // Global variable to keep track of steps

void moveDisk(char from, char to, int disk) {
    printf("Step %d: Move disk %d from %c to %c\n", ++stepCount, disk, from, to);
}

void towerOfHanoi(int disk, char fromRod, char toRod, char auxRod) {
    if (disk == 1) { // Base case: Move the disk from fromRod to toRod
        moveDisk(fromRod, toRod, disk);
        return;
    }
    // Move top n-1 disks from fromRod to auxRod
    towerOfHanoi(disk - 1, fromRod, auxRod, toRod);
    // Move the nth disk from fromRod to toRod
    moveDisk(fromRod, toRod, disk);
    // Move the n-1 disks from auxRod to toRod
    towerOfHanoi(disk - 1, auxRod, toRod, fromRod);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    // Calling the function to solve the problem
    printf("The solution to the Tower of Hanoi problem with %d discs is:\n", disks);
    towerOfHanoi(disks, 'A', 'C', 'B');
    printf("Total number of steps: %d\n", stepCount);
    return 0;
}