//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// function prototype
void towerOfHanoi(int n, char source, char destination, char auxiliary);

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid input. Number of disks must be greater than or equal to 1.\n");
        return 0;
    }
    printf("The steps to solve the Tower of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c.\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c.\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}