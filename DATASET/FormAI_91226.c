//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include <stdio.h>

// Function to move a disk from a peg to another peg
void moveDisk(int diskNumber, char sourcePeg, char destPeg) {
    printf("Move disk %d from peg %c to peg %c\n", diskNumber, sourcePeg, destPeg);
}

// Function to solve Tower of Hanoi problem
void solveTowerOfHanoi(int numberOfDisks, char sourcePeg, char auxPeg, char destPeg) {
    if (numberOfDisks == 0) {
        return;
    }
    solveTowerOfHanoi(numberOfDisks - 1, sourcePeg, destPeg, auxPeg);
    moveDisk(numberOfDisks, sourcePeg, destPeg);
    solveTowerOfHanoi(numberOfDisks - 1, auxPeg, sourcePeg, destPeg);
}

int main() {
    int numberOfDisks;
    printf("Enter number of disks: ");
    scanf("%d", &numberOfDisks);

    // Initializing three pegs A, B, and C to hold the disks
    char sourcePeg = 'A', auxPeg = 'B', destPeg = 'C';

    // Solving Tower of Hanoi problem
    solveTowerOfHanoi(numberOfDisks, sourcePeg, auxPeg, destPeg);

    return 0;
}