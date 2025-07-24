//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

void moveDisk(int disk, char source, char destination)
{
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}

void towerOfHanoi(int disk, char source, char temp, char destination)
{
    if (disk == 1)
    {
        moveDisk(disk, source, destination);
        return;
    }
    towerOfHanoi(disk - 1, source, destination, temp);
    moveDisk(disk, source, destination);
    towerOfHanoi(disk - 1, temp, source, destination);
}

int main()
{
    int disk;
    printf("Enter the number of disks:\n");
    scanf("%d", &disk);

    towerOfHanoi(disk, 'A', 'B', 'C');

    return 0;
}