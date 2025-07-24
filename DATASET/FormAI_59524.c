//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void move(int n, char start, char end, char spare)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    move(n-1, start, spare, end);
    printf("Move disk %d from rod %c to rod %c\n", n, start, end);
    move(n-1, spare, end, start);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");

    if (n <= 0)
    {
        printf("Invalid input! Number of disks must be greater than 0\n");
        return 0;
    }

    printf("Solving Tower of Hanoi problem for %d disks\n\n", n);

    move(n, 'A', 'C', 'B');

    printf("\nTower of Hanoi problem solved successfully\n");

    return 0;
}