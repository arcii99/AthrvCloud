//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("\n Move disk %d from rod %c to rod %c", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The solution for the Tower of Hanoi problem with %d disks is:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\n");
    return 0;
}