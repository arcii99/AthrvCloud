//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>

void moveDisks(int numDisks, char first, char last, char middle) {
    if (numDisks == 1) {
        printf("Move disk 1 from peg %c to peg %c.\n", first, last);
    } else {
        moveDisks(numDisks - 1, first, middle, last);
        printf("Move disk %d from peg %c to peg %c.\n", numDisks, first, last);
        moveDisks(numDisks - 1, middle, last, first);
    }
}

int main() {
    int numDisks;
    printf("Enter number of disks: ");
    scanf("%d", &numDisks);
    printf("Moves required to solve the Tower of Hanoi puzzle:\n");
    moveDisks(numDisks, 'A', 'C', 'B');
    return 0;
}