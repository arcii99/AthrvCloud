//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>

// Function to implement the tower of Hanoi problem
void towerOfHanoi(int n, char source_rod, char destination_rod, char aux_rod)
{
    if (n == 1) // Base case
    {
        printf("\n Move disk 1 from rod %c to rod %c", source_rod, destination_rod);
        return;
    }

    // Move n-1 disks from source rod to auxiliary rod
    towerOfHanoi(n-1, source_rod, aux_rod, destination_rod);

    // Move remaining one disk from source rod to destination rod
    printf("\n Move disk %d from rod %c to rod %c", n, source_rod, destination_rod);

    // Move n-1 disks from auxiliary rod to destination rod
    towerOfHanoi(n-1, aux_rod, destination_rod, source_rod);
}

int main()
{
    int n;
    printf("\n Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}