//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

// function to perform tower of hanoi
void towerOfHanoi(int n, char sourceRod, char destRod, char auxRod)
{
    if (n == 1) // base case
    {
        printf("Move disk 1 from %c rod to %c rod\n", sourceRod, destRod);
        return;
    }
    towerOfHanoi(n - 1, sourceRod, auxRod, destRod); // recursive call
    printf("Move disk %d from %c rod to %c rod\n", n, sourceRod, destRod);
    towerOfHanoi(n - 1, auxRod, destRod, sourceRod); // recursive call
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid input! Number of disks should be greater than or equal to 1.");
        return 1;
    }
    printf("Solution for Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}