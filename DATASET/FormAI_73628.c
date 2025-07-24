//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void hanoi(char start, char end, char aux, int n) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c.\n", start, end);
        return;
    }
    hanoi(start, aux, end, n - 1);
    printf("Move disk %d from %c to %c.\n", n, start, end);
    hanoi(aux, end, start, n - 1);
}

int main() {
    int n;
    char start = 'A', aux = 'B', end = 'C';
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > 10) {
        printf("Invalid number of disks. Choose a number between 1 and 10.\n");
        exit(1);
    }
    printf("The steps to solve Tower of Hanoi problem with %d disks are:\n", n);
    hanoi(start, end, aux, n);
    return 0;
}