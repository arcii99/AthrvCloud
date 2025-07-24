//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>

void moveTower(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    moveTower(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveTower(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    printf("Tower of Hanoi problem with %d disks:\n", n);
    moveTower(n, 'A', 'B', 'C');
    return 0;
}