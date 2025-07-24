//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

void moveDisk(int n, char sourceRod, char destinationRod, char auxiliaryRod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", sourceRod, destinationRod);
        return;
    }
    moveDisk(n - 1, sourceRod, auxiliaryRod, destinationRod);
    printf("\n Move disk %d from rod %c to rod %c", n, sourceRod, destinationRod);
    moveDisk(n - 1, auxiliaryRod, destinationRod, sourceRod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nTower of Hanoi with %d disks:", n);
    moveDisk(n, 'A', 'C', 'B');
    return 0;
}