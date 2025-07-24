//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include<stdio.h>

// Function to solve the tower of hanoi problem
void towerOfHanoi(int n, char sourceRod, char destinationRod, char auxiliaryRod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", sourceRod, destinationRod);
        return;
    }
    towerOfHanoi(n - 1, sourceRod, auxiliaryRod, destinationRod);
    printf("\n Move disk %d from rod %c to rod %c", n, sourceRod, destinationRod);
    towerOfHanoi(n - 1, auxiliaryRod, destinationRod, sourceRod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nSequence of disk movements: ");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}