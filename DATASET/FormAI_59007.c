//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include<stdio.h>

// function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod);
        return;
    }

    // move the top n-1 disks from A to B
    towerOfHanoi(n-1, source_rod, auxiliary_rod, destination_rod);

    // move the nth disk from A to C
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, destination_rod);

    // move the top n-1 disks from B to C
    towerOfHanoi(n-1, auxiliary_rod, destination_rod, source_rod);
}

int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of the rods

    return 0;
}