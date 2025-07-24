//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>

int count = 0;

// Function to move disk from source to destination
void moveDisk(char source, char destination) {
    printf("Move disk %d from %c to %c\n", count++, source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if(numDisks == 1) {
        moveDisk(source, destination);
        return;
    }
    towerOfHanoi(numDisks-1, source, destination, auxiliary);
    moveDisk(source, destination);
    towerOfHanoi(numDisks-1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}