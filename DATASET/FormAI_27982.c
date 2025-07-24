//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>

void moveDisc(int fromPeg, int toPeg) {
    printf("Move disc from peg %d to peg %d\n", fromPeg, toPeg);
}

void towerOfHanoi(int n, int sourcePeg, int destinationPeg, int auxiliaryPeg) {
    if(n == 0) {
        return;
    }
    towerOfHanoi(n-1, sourcePeg, auxiliaryPeg, destinationPeg);
    moveDisc(sourcePeg, destinationPeg);
    towerOfHanoi(n-1, auxiliaryPeg, destinationPeg, sourcePeg);
}

int main() {
    int n = 3;
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    towerOfHanoi(n, 1, 3, 2);
    return 0;
}