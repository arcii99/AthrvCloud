//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>

// Recursive function to solve the Tower of Hanoi
void tower_of_hanoi(int discs, char from_rod, char to_rod, char aux_rod)
{
    if (discs == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(discs - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", discs, from_rod, to_rod);
    tower_of_hanoi(discs - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int discs = 4; // Number of discs
    tower_of_hanoi(discs, 'A', 'C', 'B'); // A, B and C are the three rods
    return 0;
}