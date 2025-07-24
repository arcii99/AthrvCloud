//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("\n Move Disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move Disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n\nTower of Hanoi solution for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}