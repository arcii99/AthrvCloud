//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

// Declare the function for Tower of Hanoi
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {

    // If only one disk is present,move it from starting rod to the end rod
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    // Recursively call function to move n-1 disks from starting rod to auxiliary rod using ending rod as a support
    towerOfHanoi(n-1, fromRod, auxRod, toRod);

    // Move the n-th disk from starting rod to ending rod
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);

    // Recursively call function to move n-1 disks from auxiliary rod to ending rod using starting rod as a support
    towerOfHanoi(n-1, auxRod, toRod, fromRod);

}

int main() {

    int numberOfDisks;

    printf("Welcome to Tower of Hanoi!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &numberOfDisks);
    printf("\n");

    // Call function to move disks from rod A to rod C using rod B as a support
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');

    printf("\nThank you for playing Tower of Hanoi!\n");

    return 0;
}