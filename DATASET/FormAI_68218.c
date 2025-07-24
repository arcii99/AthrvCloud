//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>

/* Function to move disks from peg 'src' to peg 'dest' using peg 'temp' as buffer */
void towerOfHanoi(int n, char src, char dest, char temp)
{
    if (n == 1) // Base case: only one disk to be moved
    {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }

    // Move top n-1 disks from 'src' to 'temp', using 'dest' as buffer
    towerOfHanoi(n-1, src, temp, dest);

    // Move remaining 1 disk from 'src' to 'dest'
    printf("Move disk %d from %c to %c\n", n, src, dest);

    // Move top n-1 disks from 'temp' to 'dest', using 'src' as buffer
    towerOfHanoi(n-1, temp, dest, src);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid input. Number of disks should be positive.\n");
        return 1;
    }

    printf("Moves required to solve Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}