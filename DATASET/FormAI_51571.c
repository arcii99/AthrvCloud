//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>

void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod);
        return;
    }
    towerOfHanoi(n-1, source_rod, auxiliary_rod, destination_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, destination_rod);
    towerOfHanoi(n-1, auxiliary_rod, destination_rod, source_rod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}