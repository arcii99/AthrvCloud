//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>

void moveTower(int disk, char source, char target, char auxiliary) {
    if (disk > 0) {
        moveTower(disk - 1, source, auxiliary, target);
        printf("Move disk %d from %c to %c\n", disk, source, target);
        moveTower(disk - 1, auxiliary, target, source);
    }
}

int main() {
    int numDisks;

    printf("Enter number of disks: ");
    scanf("%d", &numDisks);

    moveTower(numDisks, 'A', 'C', 'B');

    return 0;
}