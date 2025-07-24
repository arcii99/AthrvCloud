//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }

    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n<1)
    {
        printf("Invalid input\n");
        return 0;
    }

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}