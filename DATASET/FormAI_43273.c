//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>

void moveDisk(char source, char dest, int disk) {
    printf("Move disk %d from %c to %c\n", disk, source, dest);
}

void towerOfHanoi(int diskQty, char source, char aux, char dest) {
    if (diskQty == 1) {
        moveDisk(source, dest, 1);
        return;
    }
    towerOfHanoi(diskQty - 1, source, dest, aux);
    moveDisk(source, dest, diskQty);
    towerOfHanoi(diskQty - 1, aux, source, dest);
}

int main() {
    int diskQty;

    printf("Enter number of disks: ");
    scanf("%d", &diskQty);

    towerOfHanoi(diskQty, 'A', 'B', 'C');

    return 0;
}