//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

void move(int n, char start_rod, char end_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", start_rod, end_rod);
        return;
    }
    move(n-1, start_rod, aux_rod, end_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, start_rod, end_rod);
    move(n-1, aux_rod, end_rod, start_rod);
}

int main() {
    int num_disks = 4;
    move(num_disks, 'A', 'C', 'B');
    return 0;
}