//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>

void towerOfHanoi(int n, char source, char aux, char dest) {
    if(n == 1) {
        printf("Move Disk 1 from %c to %c\n", source, dest);
        return;
    }

    towerOfHanoi(n-1, source, dest, aux);
    printf("Move Disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n-1, aux, source, dest);
}

int main() {
    int n = 4;
    printf("Tower of Hanoi for %d disks\n\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}