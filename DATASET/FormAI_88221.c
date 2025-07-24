//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>

void moveDisk(char disk, char source, char dest) {
    printf("%c move from %c to %c\n", disk, source, dest);
}

void solveHanoi(int numDisks, char source, char dest, char auxiliary) {
    if (numDisks == 1) {
        moveDisk('1', source, dest);
        return;
    }
    solveHanoi(numDisks - 1, source, auxiliary, dest);
    moveDisk(numDisks + '0', source, dest);
    solveHanoi(numDisks - 1, auxiliary, dest, source);
}

int main() {
    int numDisks = 4;
    printf("Welcome to the Tower of Hanoi, where you will witness the power of recursion!\n");
    printf("%d disks on rod A, getting ready to move to rod C!\n", numDisks);
    solveHanoi(numDisks, 'A', 'C', 'B');
    printf("\nCongratulations! You have successfully solved the Tower of Hanoi problem!\n");
    return 0;
}