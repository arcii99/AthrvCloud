//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void towerHanoi(int n, char fromTow, char toTow, char auxTow)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", fromTow, toTow);
        return;
    }
    towerHanoi(n-1, fromTow, auxTow, toTow);
    printf("Move disk %d from tower %c to tower %c\n", n, fromTow, toTow);
    towerHanoi(n-1, auxTow, toTow, fromTow);
}

int main()
{
    int numDisk;
    printf("Welcome to the Tower of Hanoi problem solver!\n");
    printf("Please enter number of disks: ");
    scanf("%d", &numDisk);
    printf("The solution of the Tower of Hanoi problem with %d disks is:\n", numDisk);
    towerHanoi(numDisk, 'A', 'C', 'B'); // A, B and C are names of towers
    printf("Program completed! All disks have been moved to destination tower :)\n");
    return 0;
}