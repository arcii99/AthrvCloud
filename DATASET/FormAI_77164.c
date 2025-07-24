//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_of_disks = 3;
    char start_rod = 'A', end_rod = 'C', temp_rod = 'B';

    printf("Tower of Hanoi problem with %d disks:\n\n", num_of_disks);
    towerOfHanoi(num_of_disks, start_rod, end_rod, temp_rod);

    return 0;
}