//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void move(int disks, char pole1, char pole2, char pole3)
{
    if (disks == 1)
    {
        printf("Move disk 1 from %c to %c\n", pole1, pole3);
        return;
    }

    move(disks - 1, pole1, pole3, pole2);
    printf("Move disk %d from %c to %c\n", disks, pole1, pole3);
    move(disks - 1, pole2, pole1, pole3);
}

int main()
{
    int disks;

    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    if (disks < 1)
    {
        printf("Invalid input\n");
        return 0;
    }

    move(disks, 'A', 'B', 'C');

    return 0;
}