//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

// Function to move a disk from origin to destination peg
void moveDisk(int disk, char origin, char destination)
{
    printf("Move disk %d from Peg %c to Peg %c\n", disk, origin, destination);
}

// Recursive function to solve the Tower of Hanoi puzzle
void towerOfHanoi(int disk, char source, char auxiliary, char destination)
{
    if (disk == 0)
    {
        return;
    }
    else if (disk == 1)
    {
        moveDisk(disk, source, destination);
    }
    else
    {
        towerOfHanoi(disk-1, source, destination, auxiliary);
        moveDisk(disk, source, destination);
        towerOfHanoi(disk-1, auxiliary, source, destination);
    }
}

int main()
{
    int numOfDisks;

    printf("Welcome to the Tower of Hanoi problem solver!");
    printf("\nEnter the number of disks: ");
    scanf("%d", &numOfDisks);

    if (numOfDisks < 1)
    {
        printf("Error: Number of disks must be a positive integer.\n");
        return -1;
    }

    printf("\nSolving the Tower of Hanoi problem for %d disks:\n", numOfDisks);
    towerOfHanoi(numOfDisks, 'A', 'B', 'C');
    printf("\nProblem solved! Thanks for using the program.");
    return 0;
}