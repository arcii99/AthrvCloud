//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>

void tower_of_hanoi(int num_disks, char from_rod, char to_rod, char aux_rod)
{
    if (num_disks == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(num_disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", num_disks, from_rod, to_rod);
    tower_of_hanoi(num_disks - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}