//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>

void towerOfHanoi(int numDisks, char srcPeg, char destPeg, char auxPeg) {
    if(numDisks == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", srcPeg, destPeg);
        return;
    }

    towerOfHanoi(numDisks - 1, srcPeg, auxPeg, destPeg);
    printf("Move disk %d from peg %c to peg %c\n", numDisks, srcPeg, destPeg);
    towerOfHanoi(numDisks - 1, auxPeg, destPeg, srcPeg);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if(numDisks <= 0) {
        printf("Invalid input. Enter a valid, positive integer.\n");
        return 0;
    }

    printf("The solution to the Tower of Hanoi problem for %d disks is:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    return 0;
}