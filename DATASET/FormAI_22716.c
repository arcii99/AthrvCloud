//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>

// function prototypes
void solveTowerOfHanoi(int, char, char, char);

// main function
int main() {
    int numDisks;

    // prompt user to enter number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // solving Tower of Hanoi problem
    solveTowerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}

// function to solve Tower of Hanoi problem recursively
void solveTowerOfHanoi(int numDisks, char sourceRod, char destinationRod, char auxiliaryRod) {
    if(numDisks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", sourceRod, destinationRod);
        return;
    }
    solveTowerOfHanoi(numDisks - 1, sourceRod, auxiliaryRod, destinationRod);
    printf("Move disk %d from rod %c to rod %c\n", numDisks, sourceRod, destinationRod);
    solveTowerOfHanoi(numDisks - 1, auxiliaryRod, destinationRod, sourceRod);
}