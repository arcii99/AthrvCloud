//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("\n Move disk %d from rod %c to rod %c", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 4;  // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are the rods
    return 0;
}