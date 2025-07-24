//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

// Recursive function to solve the tower of Hanoi problem
void towerOfHanoi(int n, char rodFrom, char rodTo, char rodAux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", rodFrom, rodTo);
        return;
    }
    towerOfHanoi(n-1, rodFrom, rodAux, rodTo);
    printf("Move disk %d from rod %c to rod %c\n", n, rodFrom, rodTo);
    towerOfHanoi(n-1, rodAux, rodTo, rodFrom);
}

int main() {
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are the names of rods
    return 0;
}