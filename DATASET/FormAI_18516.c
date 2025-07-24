//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    return 0;
}