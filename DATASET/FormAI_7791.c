//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>

void moveTower(int disks, char source, char destination, char intermediate) {
    if (disks >= 1) {
        moveTower(disks - 1, source, intermediate, destination);
        printf("Move disk %d from %c to %c\n", disks, source, destination);
        moveTower(disks - 1, intermediate, destination, source);
    }
}

int main() {
    int diskCount;
    printf("How many disks are there? ");
    scanf("%d", &diskCount);

    moveTower(diskCount, 'A', 'C', 'B');

    return 0;
}