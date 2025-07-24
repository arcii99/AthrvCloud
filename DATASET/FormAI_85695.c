//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>

void towers(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c.", from_rod, to_rod);
        return;
    }
    towers(n-1, from_rod, aux_rod, to_rod);
    printf("\nMove disk %d from rod %c to rod %c.", n, from_rod, to_rod);
    towers(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towers(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}