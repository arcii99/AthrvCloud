//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if(num_disks < 1){
        printf("The number of disk must be greater or equal to 1\n");
        return 0;
    }
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    return 0;
}