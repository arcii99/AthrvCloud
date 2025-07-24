//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }

    towerOfHanoi(n - 1, source, aux, dest);
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    towerOfHanoi(n - 1, aux, dest, source);
}

int main() {
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods

    return 0;
}