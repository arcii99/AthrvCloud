//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>

void move(int n, char source, char destination, char auxiliary) {
    if(n <= 0) {
        return;
    }

    move(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    move(n-1, auxiliary, destination, source);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if(numDisks <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }

    printf("Steps to solve the Tower of Hanoi problem with %d disks:\n", numDisks);
    move(numDisks, 'A', 'C', 'B');

    return 0;
}