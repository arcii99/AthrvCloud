//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int moves = 0;

void moveDisk(char fromRod, char toRod, int disk)
{
    printf("Move disk %d from %c to %c\n", disk, fromRod, toRod);
    moves++;
}

void towerOfHanoi(int disks, char fromRod, char toRod, char tempRod)
{
    if(disks == 1)
    {
        moveDisk(fromRod, toRod, disks);
        return;
    }
    
    towerOfHanoi(disks-1, fromRod, tempRod, toRod);
    moveDisk(fromRod, toRod, disks);
    towerOfHanoi(disks-1, tempRod, toRod, fromRod);
}

int main()
{
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    
    if(disks <= 0)
    {
        printf("Invalid input!\n");
        return 0;
    }
    
    printf("The solution to Tower of Hanoi problem for %d disks is:\n", disks);
    towerOfHanoi(disks, 'A', 'C', 'B');
    printf("Total number of moves = %d\n", moves);
    
    return 0;
}