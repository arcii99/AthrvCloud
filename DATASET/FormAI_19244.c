//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>

void towersOfHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    towersOfHanoi(n-1, A, C, B);
    printf("Move disk %d from %c to %c\n", n, A, C);
    towersOfHanoi(n-1, B, A, C);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The moves involved in the Tower of Hanoi are:\n");
    towersOfHanoi(n, 'A', 'B', 'C');
    return 0;
}