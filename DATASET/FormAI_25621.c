//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include<stdio.h>

//Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source_rod, char aux_rod, char destination_rod)
{
    if(n==1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", source_rod, destination_rod);
        return;
    }
    towerOfHanoi(n-1, source_rod, destination_rod, aux_rod);
    printf("\nMove disk %d from rod %c to rod %c", n, source_rod, destination_rod);
    towerOfHanoi(n-1, aux_rod, source_rod, destination_rod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}