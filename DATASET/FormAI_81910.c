//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>

void moveDisk(char from, char to, int disk)
{
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void towerOfHanoi(int disk, char source, char destination, char auxiliary)
{
    if (disk == 1)
    {
        moveDisk(source, destination, disk);
        return;
    }

    towerOfHanoi(disk - 1, source, auxiliary, destination);
    moveDisk(source, destination, disk);
    towerOfHanoi(disk - 1, auxiliary, destination, source);
}

int main()
{
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    printf("\nThe solution for Tower of Hanoi problem with %d disks:\n\n", disks);

    towerOfHanoi(disks, 'A', 'C', 'B');

    printf("\n");

    return 0;
}