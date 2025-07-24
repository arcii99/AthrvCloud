//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>

// function prototype
void hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int n = 3; // number of disks
    printf("Tower of Hanoi problem with %d disks:\n\n", n);
    hanoi(n, 'A', 'C', 'B'); // A, B and C are the rods
    return 0;
}

// recursive function to solve Tower of Hanoi
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) { // base case
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    // move n-1 disks from from_rod to aux_rod using to_rod
    hanoi(n-1, from_rod, aux_rod, to_rod);
    // move the remaining disk from from_rod to to_rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    // move n-1 disks from aux_rod to to_rod using from_rod
    hanoi(n-1, aux_rod, to_rod, from_rod);
}