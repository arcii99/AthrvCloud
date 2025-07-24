//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>

void towerOfHanoi(int, char, char, char);

int main() {
    int numDisks = 3; // change this to set the number of disks
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    return 0;
}

void towerOfHanoi(int numDisks, char source, char destination, char auxiliary) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(numDisks - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);
    towerOfHanoi(numDisks - 1, auxiliary, destination, source);
}