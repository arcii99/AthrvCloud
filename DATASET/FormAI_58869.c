//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>

void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from rod %c to rod %c\n", disk, source, destination);
}

void towerOfHanoi(int numDisks, char source, char destination, char spare) {
    if (numDisks == 1) {
        moveDisk(numDisks, source, destination);
        return;
    }
    
    towerOfHanoi(numDisks - 1, source, spare, destination);
    moveDisk(numDisks, source, destination);
    towerOfHanoi(numDisks - 1, spare, destination, source);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    towerOfHanoi(numDisks, 'A', 'C', 'B');
    return 0;
}