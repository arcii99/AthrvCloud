//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

// Function prototypes
void moveDisk(int, char, char, char);
void towerOfHanoi(int, char, char, char);

int main() {
    int numDisks = 3; // Number of disks
    printf("Tower of Hanoi problem with %d disks\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B'); // A, B, and C are the names of the towers
    return 0;
}

// Recursive function to move the disks from source to destination tower
void towerOfHanoi(int numDisks, char source, char destination, char auxiliary) {
    if (numDisks == 1) { // Only one disk left to move
        moveDisk(numDisks, source, destination, auxiliary);
        return;
    }
    towerOfHanoi(numDisks - 1, source, auxiliary, destination); // Move n-1 disks from source to auxiliary tower
    moveDisk(numDisks, source, destination, auxiliary); // Move nth disk from source to destination tower
    towerOfHanoi(numDisks - 1, auxiliary, destination, source); // Move n - 1 disks from auxiliary to destination tower
}

// Function to print the movement of disks
void moveDisk(int disk, char source, char destination, char auxiliary) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}