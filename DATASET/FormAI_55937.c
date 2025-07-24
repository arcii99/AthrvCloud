//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>

// Function to move the disk from source to destination
void move(int disk, char source, char destination)
{
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

// Function for tower of hanoi puzzle
void towerOfHanoi(int disks, char source, char auxiliary, char destination)
{
    if (disks == 1) // Base case for recursion
    {
        move(disks, source, destination);
        return;
    }
    towerOfHanoi(disks-1, source, destination, auxiliary);
    move(disks, source, destination);
    towerOfHanoi(disks-1, auxiliary, source, destination);
}

int main()
{
    int disks = 3;
    towerOfHanoi(disks, 'A', 'B', 'C');
    return 0;
}