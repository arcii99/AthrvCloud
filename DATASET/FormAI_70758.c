//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void moveTower(int n, char sourceRod, char destRod, char auxRod) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", sourceRod, destRod);
        return;
    }
    moveTower(n - 1, sourceRod, auxRod, destRod);
    printf("Move disk %d from rod %c to rod %c.\n", n, sourceRod, destRod);
    moveTower(n - 1, auxRod, destRod, sourceRod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n < 1) {
        printf("Invalid input. Number of disks must be greater than or equal to 1.\n");
        return 0;
    }
    moveTower(n, 'A', 'C', 'B');
    return 0;
}