//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>

void moveDisk(char fromRod, char toRod, int diskNumber) {
    printf("Move disk %d from rod %c to rod %c\n", diskNumber, fromRod, toRod);
}

void towerOfHanoi(int numberOfDisks, char fromRod, char toRod, char auxRod) {
    if (numberOfDisks == 1) {
        moveDisk(fromRod, toRod, numberOfDisks);
        return;
    }
    towerOfHanoi(numberOfDisks - 1, fromRod, auxRod, toRod);
    moveDisk(fromRod, toRod, numberOfDisks);
    towerOfHanoi(numberOfDisks -1, auxRod, toRod, fromRod);
}

int main() {
    int numberOfDisks = 4;
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');
    return 0;
}