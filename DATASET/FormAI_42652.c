//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Touring
#include <stdio.h>

/* function to move disk */
void move(int disk, char source, char dest)
{
    printf("Move disk %d from %c to %c\n", disk, source, dest);
}

/* recursive function to solve Tower of Hanoi */
void towerOfHanoi(int disks, char source, char temp, char dest)
{
    if (disks == 1)
    {
        move(disks, source, dest);
        return;
    }

    towerOfHanoi(disks - 1, source, dest, temp);
    move(disks, source, dest);
    towerOfHanoi(disks - 1, temp, source, dest);
}

/* main function */
int main()
{
    int disks = 3;
    char source = 'A', temp = 'B', dest = 'C';

    printf("******** TOWER OF HANOI ********\n\n");

    printf("Number of disks: %d\n", disks);
    printf("Source: %c, Temporary: %c, Destination: %c\n\n", source, temp, dest);

    towerOfHanoi(disks, source, temp, dest);

    return 0;
}