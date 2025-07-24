//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>

void move(char from_rod, char to_rod)
{
    printf("Move disk from %c to %c\n", from_rod, to_rod);
}

void towerOfHanoi(int num_disks, char from_rod, char to_rod, char aux_rod)
{
    if (num_disks == 1)
    {
        move(from_rod, to_rod);
        return;
    }
 
    towerOfHanoi(num_disks-1, from_rod, aux_rod, to_rod);
    move(from_rod, to_rod);
    towerOfHanoi(num_disks-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num_disks = 3;
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    return 0;
}