//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include<stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\n Move disk %d from %c to %c", n, from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from %c to %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks in Tower of Hanoi: ");
    scanf("%d", &n);
    printf("The Tower of Hanoi solution is:\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}