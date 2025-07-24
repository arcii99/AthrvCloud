//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>

void moveDisk(int diskNum, int src, int dest) {
    printf("Move disk %d from Tower %d to Tower %d\n", diskNum, src, dest);
}

void towerOfHanoi(int numDisks, int src, int aux, int dest) {
    if (numDisks == 1) {
        moveDisk(numDisks, src, dest);
        return;
    }
    towerOfHanoi(numDisks - 1, src, dest, aux);
    moveDisk(numDisks, src, dest);
    towerOfHanoi(numDisks - 1, aux, src, dest);
}

int main() {
    int n;
    printf("\nWelcome to the Tower of Hanoi Challenge. In this game, you will be tasked with solving the puzzle of moving disks from one tower to another without placing a larger disk on top of a smaller disk. Good luck!\n\n");
    printf("Enter the number of disks you would like to use (minimum 3):\n");
    scanf("%d", &n);
    while (n < 3) {
        printf("Please enter a number greater than or equal to 3:\n");
        scanf("%d", &n);
    }
    printf("\nYou have chosen to use %d disks. The solution is as follows:\n\n", n);
    towerOfHanoi(n, 1, 2, 3);
    printf("\nCongratulations, you have solved the Tower of Hanoi puzzle!");
    return 0;
}