//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void towersOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if(n==1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towersOfHanoi(n-1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towersOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d",&num_disks);

    if(num_disks < 1)
    {
        printf("Invalid input! Number of disks should be greater than or equal to 1.\n");
        return 0;
    }

    printf("\nSteps to solve the Tower of Hanoi problem:\n\n");
    towersOfHanoi(num_disks, 'A', 'B', 'C');

    return 0;
}