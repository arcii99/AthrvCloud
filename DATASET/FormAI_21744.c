//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int, char, char, char);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if(n==1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}