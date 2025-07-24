//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>

void moveDisks(int numDisks, char rodFrom, char rodMiddle, char rodTo);

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    moveDisks(numDisks, 'A', 'B', 'C');

    return 0;
}

void moveDisks(int numDisks, char rodFrom, char rodMiddle, char rodTo) {
    if (numDisks == 0) {
        return;
    }

    moveDisks(numDisks - 1, rodFrom, rodTo, rodMiddle);

    printf("Move disk %d from rod %c to rod %c\n", numDisks, rodFrom, rodTo);

    moveDisks(numDisks - 1, rodMiddle, rodFrom, rodTo);
}