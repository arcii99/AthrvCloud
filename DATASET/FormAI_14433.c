//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: romantic
#include <stdio.h>

void moveTower(int, char, char, char);

int main()
{
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    moveTower(disks, 'A', 'C', 'B');
    return 0;
}

void moveTower(int disk, char source, char dest, char temp)
{
    if (disk == 1)
    {
        printf("Move disk 1 from pole %c to pole %c\n", source, dest);
        return;
    }
    moveTower(disk - 1, source, temp, dest);
    printf("Move disk %d from pole %c to pole %c\n", disk, source, dest);
    moveTower(disk - 1, temp, dest, source);
}