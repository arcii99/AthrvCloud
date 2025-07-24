//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

void main()
{
    int num_disks = 4; // number of disks in the tower
    char rodA = 'A', rodB = 'B', rodC = 'C';

    // initialize the seed for the random number generator
    srand(time(NULL));

    printf("Welcome to the Tower of Hanoi problem!\n");

    // randomly generate the number of disks in the tower
    num_disks = rand() % 10 + 1;

    printf("\nNumber of disks: %d\n", num_disks);

    towerOfHanoi(num_disks, rodA, rodC, rodB);

    printf("\n\nProgram completed successfully.\n");

}