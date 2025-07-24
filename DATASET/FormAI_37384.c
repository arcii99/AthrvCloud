//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(int num_disks, char from_rod, char to_rod, char aux_rod)
{
    if (num_disks == 1) {
       printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
       return;
    }
    tower_of_hanoi(num_disks - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", num_disks, from_rod, to_rod);
    tower_of_hanoi(num_disks - 1, aux_rod, to_rod, from_rod);
}

int main(void)
{
    int num_disks = 0;
    char from_rod = 'A', to_rod = 'C', aux_rod = 'B';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1){
        printf("Invalid number of disks entered.\n");
        return EXIT_FAILURE;
    }

    printf("\nTower of Hanoi solution for %d disks:\n", num_disks);
    tower_of_hanoi(num_disks, from_rod, to_rod, aux_rod);

    return EXIT_SUCCESS;
}