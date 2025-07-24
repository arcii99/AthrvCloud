//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// function to move disks from source to destination
void moveDisks(int n, char source, char destination, char auxillary) {
    if (n == 1) {
        printf("Move Disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisks(n-1, source, auxillary, destination);
    printf("Move Disk %d from %c to %c\n", n, source, destination);
    moveDisks(n-1, auxillary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // validate input
    if (n <= 0) {
        printf("The number of disks must be greater than zero.\n");
        exit(0);
    }

    printf("The solution for Tower of Hanoi problem is:\n");
    moveDisks(n, 'A', 'B', 'C');

    return 0;
}