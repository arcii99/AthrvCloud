//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Welcome to the Tower of Hanoi problem!\n");
    printf("Enter the number of disks to move: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid input, please enter a positive integer.\n");
        return 0;
    }
    printf("Here is the solution to the Tower of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("Thank you for using this program!\n");
    return 0;
}