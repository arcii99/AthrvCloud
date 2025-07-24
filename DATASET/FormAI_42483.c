//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>

void solveTowerOfHanoi(int numDiscs, char sourceRod, char destinationRod, char auxiliaryRod) {
    if (numDiscs == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", sourceRod, destinationRod);
        return;
    }

    solveTowerOfHanoi(numDiscs - 1, sourceRod, auxiliaryRod, destinationRod);
    printf("Move disk %d from rod %c to rod %c\n", numDiscs, sourceRod, destinationRod);
    solveTowerOfHanoi(numDiscs - 1, auxiliaryRod, destinationRod, sourceRod);
}

int main() {
    int numDiscs;
    
    printf("Enter the number of discs: ");
    scanf("%d", &numDiscs);

    solveTowerOfHanoi(numDiscs, 'A', 'C', 'B'); // A is source rod, C is destination rod, B is auxiliary rod

    return 0;
}