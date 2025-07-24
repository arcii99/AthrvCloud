//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // Move the single disk from the initial rod to the target rod
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod); // Move n-1 disks from the initial rod to the auxiliary rod
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); // Move the remaining single disk from the initial rod to the target rod
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod); // Move the remaining n-1 disks from the auxiliary rod to the target rod
}

int main()
{
    int num_disks = 4; // number of disks to be moved
    
    tower_of_hanoi(num_disks, 'A', 'B', 'C'); // calling the function
    
    return 0;
}