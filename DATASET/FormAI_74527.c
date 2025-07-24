//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxillary) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    } 

    towerOfHanoi(n - 1, source, auxillary, destination);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    towerOfHanoi(n - 1, auxillary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nHere are the moves to solve the Tower of Hanoi puzzle:\n");
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}