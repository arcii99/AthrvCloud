//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

void towerOfHanoi(int n, char start_rod, char aux_rod, char end_rod)
{
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c\n", start_rod, end_rod);
        return;
    }
    towerOfHanoi(n - 1, start_rod, end_rod, aux_rod);
    printf("\nMove disk %d from rod %c to rod %c\n", n, start_rod, end_rod);
    towerOfHanoi(n - 1, aux_rod, start_rod, end_rod);
}

int main()
{
    int n = 4;
    printf("This is a unique Tower of Hanoi problem program example with %d disks\n\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}