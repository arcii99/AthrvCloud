//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

// Function to move disks between rods
void moveDisk(char fromRod, char toRod, int diskNum)
{
    printf("Move disk %d from %c rod to %c rod\n", diskNum, fromRod, toRod);
}

// Recursive function to solve Tower of Hanoi Problem
void towerOfHanoi(int disks, char srcRod, char destRod, char auxRod)
{
    if (disks == 1) // Base case: Only one disk remaining
    {
        moveDisk(srcRod, destRod, 1);
        return;
    }
    // Move top n-1 disks from srcRod to auxRod using destRod as auxiliary rod
    towerOfHanoi(disks - 1, srcRod, auxRod, destRod);
    // Move bottom disk from srcRod to destRod
    moveDisk(srcRod, destRod, disks);
    // Move top n-1 disks from auxRod to destRod using srcRod as auxiliary rod
    towerOfHanoi(disks - 1, auxRod, destRod, srcRod);
}

int main()
{
    int numDisks;
    printf("Enter number of disks (minimum 3): ");
    scanf("%d", &numDisks);
    if (numDisks < 3)
    {
        printf("Invalid input! Number of disks must be at least 3.\n");
        return 1;
    }
    char srcRod = 'A', auxRod = 'B', destRod = 'C'; // Rod names
    printf("\nHere are the steps to solve the Tower of Hanoi problem for %d disks:\n", numDisks);
    towerOfHanoi(numDisks, srcRod, destRod, auxRod);
    return 0;
}