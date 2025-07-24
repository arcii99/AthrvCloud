//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

void hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    hanoi(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n = 3;

    printf("The Tower of Hanoi problem for %d disks\n", n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}