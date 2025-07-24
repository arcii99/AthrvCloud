//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>

// function to move disk from source to destination peg
void moveDisk(int diskNumber, char sourcePeg, char destinationPeg)
{
    printf("Move disk %d from peg %c to peg %c\n", diskNumber, sourcePeg, destinationPeg);
}

// function to recursively solve Tower of Hanoi problem
void towerOfHanoi(int numberOfDisks, char sourcePeg, char auxiliaryPeg, char destinationPeg)
{
    if (numberOfDisks == 1)
    {
        moveDisk(numberOfDisks, sourcePeg, destinationPeg);
    }
    else
    {
        towerOfHanoi(numberOfDisks - 1, sourcePeg, destinationPeg, auxiliaryPeg);
        moveDisk(numberOfDisks, sourcePeg, destinationPeg);
        towerOfHanoi(numberOfDisks - 1, auxiliaryPeg, sourcePeg, destinationPeg);
    }
}

int main()
{
    int numberOfDisks;

    printf("Enter number of disks: ");
    scanf("%d", &numberOfDisks);

    // You can also configure the starting pegs here if you want
    towerOfHanoi(numberOfDisks, 'A', 'B', 'C');

    return 0;
}