//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>

void towerOfHanoi(int n, char rodA, char rodB, char rodC) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", rodA, rodC);
        return;
    }

    towerOfHanoi(n-1, rodA, rodC, rodB);
    printf("Move disk %d from rod %c to rod %c\n", n, rodA, rodC);
    towerOfHanoi(n-1, rodB, rodA, rodC);
}

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    towerOfHanoi(num_disks, 'A', 'B', 'C');

    return 0;
}