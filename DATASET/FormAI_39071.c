//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void moveDisk(char source, char destination, int disk) {
    printf("Move disk %d from tower %c to tower %c\n", disk, source, destination);
}

void towerOfHanoi(int n, char source, char extra, char destination) {
    if(n==1) {
        moveDisk(source, destination, n);
        return;
    }
    towerOfHanoi(n-1, source, destination, extra);
    moveDisk(source, destination, n);
    towerOfHanoi(n-1, extra, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n<=0) {
        printf("Invalid input!\n");
        return 0;
    }
    printf("\nLet's solve the Tower of Hanoi problem for %d disks!\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\nCongratulations! The problem has been solved!\n");
    return 0;
}