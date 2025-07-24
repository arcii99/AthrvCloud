//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>

void towerOfHanoi(int n, char sourceRod, char destinationRod, char auxiliaryRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", sourceRod, destinationRod);
        return;
    }
    towerOfHanoi(n - 1, sourceRod, auxiliaryRod, destinationRod);
    printf("Move disk %d from rod %c to rod %c\n", n, sourceRod, destinationRod);
    towerOfHanoi(n - 1, auxiliaryRod, destinationRod, sourceRod);
}

int main() {
    int numberOfDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numberOfDisks);

    if (numberOfDisks < 1) {
        printf("The number of disks must be greater than 0!\n");
        return 0;
    }

    printf("Welcome to Tower of Hanoi.\n");
    printf("===========================\n\n");
    printf("Initial State\n");
    printf("-------------\n\n");
    printf("Rod A: ");
    for (int i = numberOfDisks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\nRod B: \n");
    printf("Rod C: \n");

    printf("\nSolution\n");
    printf("--------\n\n");

    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');

    printf("\nFinal State\n");
    printf("-----------\n\n");
    printf("Rod A: \n");
    printf("Rod B: \n");
    printf("Rod C: ");
    for (int i = numberOfDisks; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}