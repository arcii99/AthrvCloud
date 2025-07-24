//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void towerOfHanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        moveDisk(from, to, n);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    moveDisk(from, to, n);
    towerOfHanoi(n-1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}