//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
#include <stdio.h>

void solveTowers(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disc 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    solveTowers(n-1, from_rod, aux_rod, to_rod);
    printf("Move disc %d from rod %c to rod %c\n", n, from_rod, to_rod);
    solveTowers(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_discs;
    printf("Enter the number of discs: ");
    scanf("%d", &num_discs);
    solveTowers(num_discs, 'A', 'C', 'B');
    return 0;
}