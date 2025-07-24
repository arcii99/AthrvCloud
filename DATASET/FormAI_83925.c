//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    char from_rod = 'A', to_rod = 'C', aux_rod = 'B';
    printf("Tower of Hanoi problem of %d disks:\n\n", n);
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);
    return 0;
}