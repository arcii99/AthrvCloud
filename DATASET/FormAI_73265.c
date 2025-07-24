//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>

void hanoi_tower(int n, char source_rod, char destination_rod, char aux_rod, int *count) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", source_rod, destination_rod);
        (*count)++;
        return;
    }

    hanoi_tower(n - 1, source_rod, aux_rod, destination_rod, count);
    printf("Move disk %d from rod %c to rod %c.\n", n, source_rod, destination_rod);
    (*count)++;
    hanoi_tower(n - 1, aux_rod, destination_rod, source_rod, count);
}

int main() {
    int n = 5;
    int count = 0;
    hanoi_tower(n, 'A', 'C', 'B', &count);
    printf("Total moves: %d", count);
    return 0;
}