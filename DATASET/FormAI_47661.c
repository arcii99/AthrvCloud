//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include<stdio.h>

void towers_of_hanoi(int num_disks, char from_peg, char to_peg, char spare_peg)
{
    if(num_disks == 1)
    {
        printf("\nMoving disk 1 from peg %c to peg %c", from_peg, to_peg);
        return;
    }

    towers_of_hanoi(num_disks-1, from_peg, spare_peg, to_peg);
    printf("\nMoving disk %d from peg %c to peg %c", num_disks, from_peg, to_peg);
    towers_of_hanoi(num_disks-1, spare_peg, to_peg, from_peg);
}

int main()
{
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    towers_of_hanoi(num_disks, 'A', 'C', 'B');
    printf("\n");
    return 0;
}