//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

// Function to shape shift the disks
void shapeShift(int num, char from_rod, char to_rod, char aux_rod)
{
    if (num == 1)
    {
        printf("\nShape shifting Disk %d from rod %c to rod %c", num, from_rod, to_rod);
        return;
    }
    shapeShift(num-1, from_rod, aux_rod, to_rod);
    printf("\nShape shifting Disk %d from rod %c to rod %c", num, from_rod, to_rod);
    shapeShift(num-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num_disks = 4;
    char from_rod = 'A', aux_rod = 'B', to_rod = 'C';
    
    // Initial Tower Configuration
    printf("Initial Tower Configuration\n\n");
    for(int i = num_disks; i >= 1; i--)
    {
        printf("Disk %d is on rod %c\n", i, from_rod);
    }

    // Tower of Hanoi Problem solution with shape shifting
    shapeShift(num_disks, from_rod, to_rod, aux_rod);

    // Final Tower Configuration
    printf("\n\nFinal Tower Configuration\n\n");
    for(int i = num_disks; i >= 1; i--)
    {
        printf("Disk %d is on rod %c\n", i, to_rod);
    }

    return 0;
}