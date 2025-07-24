//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 4;
    printf("The Tower of Hanoi puzzle is a classic example of recursion.\n\n");

    printf("The goal of this puzzle is to move all %d disks from the leftmost rod to the rightmost rod.\n", n);
    printf("You can only move one disk at a time.\n");
    printf("Larger disks cannot be placed on top of smaller disks.\n\n");

    printf("Step-by-step instructions to solve the puzzle:\n\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}