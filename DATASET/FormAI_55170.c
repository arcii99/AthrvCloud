//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int count = 0;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    count++;
    if (n == 1) {
        printf("Step %d: Move disk 1 from rod %c to rod %c\n", count, source, destination);
        return;
    }
    towerOfHanoi(n-1, source, auxiliary, destination);
    printf("Step %d: Move disk %d from rod %c to rod %c\n", count, n, source, destination);
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("Total Steps: %d\n", count);
    return 0;
}