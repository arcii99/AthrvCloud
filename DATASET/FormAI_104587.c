//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include<stdio.h>

// Recursive function to solve tower of hanoi problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n == 1)
    {
        printf("Move Disk 1 from Rod %c to Rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move Disk %d from Rod %c to Rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Enter the number of Disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}