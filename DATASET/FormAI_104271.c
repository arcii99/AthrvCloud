//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void moveDisk(int disk, char startPeg, char endPeg)
{
    printf("Move Disk %d from %c to %c\n", disk, startPeg, endPeg);
}

void towerOfHanoi(int disk, char startPeg, char endPeg, char extraPeg)
{
    if(disk == 1)
    {
        moveDisk(disk, startPeg, endPeg);
    }
    else
    {
        towerOfHanoi(disk-1, startPeg, extraPeg, endPeg);
        moveDisk(disk, startPeg, endPeg);
        towerOfHanoi(disk-1, extraPeg, endPeg, startPeg);
    }
}

int main()
{
    int disk = 3;
    int minMoves = (1 << disk) - 1; //calculating minimum number of moves required
    printf("Number of disks: %d\n", disk);
    printf("Minimum number of moves required: %d\n", minMoves);
    printf("Steps to solve the Tower of Hanoi problem:\n");
    towerOfHanoi(disk, 'A', 'C', 'B');
    return 0;
}