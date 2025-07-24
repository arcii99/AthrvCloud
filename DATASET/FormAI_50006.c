//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include<stdio.h>
#define MAX_SIZE 100

void move_disks(int n, char source_rod, char destination_rod, char aux_rod)
{
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", source_rod, destination_rod);
        return;
    }
    move_disks(n-1, source_rod, aux_rod, destination_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, source_rod, destination_rod);
    move_disks(n-1, aux_rod, destination_rod, source_rod);
}

int main()
{
    int num_disks;
    char source_rod = 'A', destination_rod = 'C', aux_rod = 'B';
    printf("\n-------------------------");
    printf("\n Welcome to Towers of Hanoi");
    printf("\n-------------------------");
    printf("\n Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks >= MAX_SIZE) {
        printf("\n ERROR: Maximum number of disks exceeded");
        return 1;
    }
    printf("\n Processing...");
    move_disks(num_disks, source_rod, destination_rod, aux_rod);
    printf("\n--------------------------");
    printf("\n All disks have been moved!");
    printf("\n--------------------------");
    return 0;
}