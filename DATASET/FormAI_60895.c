//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
// Tower of Hanoi problem example program in C

#include <stdio.h>

// Function to move disk from the source arm to destination arm
void moveDisk(int disk, char* source, char* destination) {
    printf("Moving disk %d from %s to %s.\n", disk, source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int disk, char* source, char* auxiliary, char* destination) {
    if (disk == 1) {
        moveDisk(disk, source, destination);
        return;
    }
    towerOfHanoi(disk-1, source, destination, auxiliary);
    moveDisk(disk, source, destination);
    towerOfHanoi(disk-1, auxiliary, source, destination);
}

// Main function to take input and invoke the towerOfHanoi function
int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    printf("The sequence of moves involved in the Tower of Hanoi problem for %d disks are:\n", disks);
    towerOfHanoi(disks, "Source", "Auxiliary", "Destination");
    return 0;
}