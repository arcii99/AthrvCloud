//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>

void towerOfHanoi(int n, char src, char temp, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }
    towerOfHanoi(n-1, src, dest, temp);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    towerOfHanoi(n-1, temp, src, dest);
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}