//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>

/* This program demonstrates the classic Tower of Hanoi problem. */

void towers(int, char, char, char);

int main()
{
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("\n\nSolution for %d disks:\n\n", num_disks);
    towers(num_disks, 'A', 'C', 'B');

    return 0;
}

void towers(int num, char source, char dest, char spare)
{
    if (num == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    towers(num - 1, source, spare, dest);
    printf("Move disk %d from %c to %c\n", num, source, dest);
    towers(num - 1, spare, dest, source);
}