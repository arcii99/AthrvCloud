//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
/* Tower of Hanoi Problem - Unique Example Program */

#include <stdio.h>

void moveDisk(int, char, char, char);
int main()
{
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    printf("The solution for %d disks is:\n", numDisks);

    moveDisk(numDisks, 'A', 'B', 'C');

    return 0;
}

void moveDisk(int num, char fromTower, char toTower, char extraTower)
{
    if (num == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", fromTower, toTower);

        printf("Performing SSH for secure transfer...\n");
        printf("Moving disk 1 from %c to %c...\n", fromTower, toTower);
        printf("Disk 1 successfully transferred.\n\n");

        return;
    }

    moveDisk(num - 1, fromTower, extraTower, toTower);
    printf("Move disk %d from tower %c to tower %c\n", num, fromTower, toTower);
    moveDisk(num - 1, extraTower, toTower, fromTower);
}