//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    if(n == 1) {
        printf("\n Move disk 1 from peg %c to peg %c", fromPeg, toPeg);
        return;
    }

    towerOfHanoi(n-1, fromPeg, auxPeg, toPeg);
    printf("\n Move disk %d from peg %c to peg %c", n, fromPeg, toPeg);
    towerOfHanoi(n-1, auxPeg, toPeg, fromPeg);
}

int main() {
    int numOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numOfDisks);

    towerOfHanoi(numOfDisks, 'A', 'C', 'B');
    
    return 0;
}