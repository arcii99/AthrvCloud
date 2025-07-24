//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>

void moveDisks(int n, char fromrod, char torod, char auxrod);

int main()
{
    int n;
    printf("Enter the number of disks for Tower of Hanoi problem:");
    scanf("%d", &n);

    printf("The solution of Tower of Hanoi problem by using %d disks is:\n", n);
    moveDisks(n, 'A', 'C', 'B');
    return 0;
}

void moveDisks(int n, char fromrod, char torod, char auxrod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromrod, torod);
        return;
    }
    moveDisks(n - 1, fromrod, auxrod, torod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromrod, torod);

    moveDisks(n - 1, auxrod, torod, fromrod);
}