//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void solveTower(int diskNum, char from, char to, char buffer) {
    if (diskNum == 1) {
        moveDisk(from, to, diskNum);
        return;
    }
    solveTower(diskNum - 1, from, buffer, to);
    moveDisk(from, to, diskNum);
    solveTower(diskNum - 1, buffer, to, from);
}

int main() {
    printf("Welcome to the Tower of Hanoi Solver!\n");
    printf("How many disks would you like to solve for? ");
    int numDisks;
    scanf("%d", &numDisks);

    printf("\nSolving Tower of Hanoi for %d disks...\n", numDisks);
    solveTower(numDisks, 'A', 'C', 'B');

    printf("\nCongratulations, the Tower of Hanoi has been solved!\n");
    return 0;
}