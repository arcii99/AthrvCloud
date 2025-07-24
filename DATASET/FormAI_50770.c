//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void towerOfHanoi(int disks, char source, char destination, char auxiliary) 
{
    if (disks == 1) 
    {
        printf("\n Move disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    towerOfHanoi(disks - 1, source, auxiliary, destination);
    printf("\n Move disk %d from rod %c to rod %c", disks, source, destination);
    towerOfHanoi(disks - 1, auxiliary, destination, source);
}

int main() 
{
    int disks = 0;
    printf("Welcome to Tower Of Hanoi problem\n");
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    if(disks<1)
    {
        printf("Invalid input. There must be at least one disk. Please try again.");
        exit(0);
    }
    printf("\nThe sequence of moves involved in the Tower of Hanoi problem with %d disks are:\n", disks);
    towerOfHanoi(disks, 'A', 'C', 'B');
    printf("\nCongratulations! The problem is solved!");
    return 0;
}