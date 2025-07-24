//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void move(int n, char start, char end, char auxiliary)
{
    count++;

    if (n == 1)
    {
        printf("Move disk %d from tower %c to tower %c\n", n, start, end);
        return;
    }

    move(n - 1, start, auxiliary, end);
    printf("Move disk %d from tower %c to tower %c\n", n, start, end);
    move(n - 1, auxiliary, end, start);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Invalid input. Number of disks should be at least 1.");
        return 0;
    }

    printf("Tower of Hanoi solution for %d disks:\n", n);
    move(n, 'A', 'C', 'B');
    printf("Number of moves: %d", count);

    return 0;
}