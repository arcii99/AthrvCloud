//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>

void moveTower(int disks, char source, char dest, char temp) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    } else {
        moveTower(disks - 1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", disks, source, dest);
        moveTower(disks - 1, temp, dest, source);
    }
}

int main() {
    int numDisks = 0;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks < 1) {
        printf("Invalid number of disks\n");
        return 1;
    }

    moveTower(numDisks, 'A', 'C', 'B');
    return 0;
}