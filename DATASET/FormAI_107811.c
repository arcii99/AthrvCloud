//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n = 3; // Number of disks
    printf("The Tower of Hanoi Problem!\n\n");
    printf("Move the disks from source rod 'A' to destination rod 'C', using the auxiliary rod 'B'.\n\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // 'A' is the source rod, 'C' is the destination rod and 'B' is the auxiliary rod
    return 0;
}