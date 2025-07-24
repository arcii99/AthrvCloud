//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// function to move disks between the poles
void moveDisk(int disk_num, char source, char dest)
{
    printf("Move disk %d from %c to %c\n", disk_num, source, dest);
}

// recursive function to implement tower of hanoi
void towerOfHanoi(int num_disks, char source, char middle, char dest)
{
    if (num_disks == 1)
    {
        moveDisk(num_disks, source, dest);
        return;
    }

    towerOfHanoi(num_disks-1, source, dest, middle);
    moveDisk(num_disks, source, dest);
    towerOfHanoi(num_disks-1, middle, source, dest);
}

// main function
int main()
{
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    towerOfHanoi(num_disks, 'A', 'B', 'C');

    return 0;
}