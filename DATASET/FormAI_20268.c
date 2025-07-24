//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void towers_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if(num_disks <= 0) {
        printf("Invalid input! Number of disks should be greater than zero.\n");
        exit(0);
    }

    towers_of_hanoi(num_disks, 'A', 'C', 'B');

    return 0;
}

void towers_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        return;
    }
    towers_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towers_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}