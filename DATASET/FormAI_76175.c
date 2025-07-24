//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include<stdio.h>

// Function to move disks from one rod to another
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n==1)
    {
        printf("\nDisk 1 moved from %c to %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\nDisk %d moved from %c to %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 3;  // number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are the tower names
    return 0;
}