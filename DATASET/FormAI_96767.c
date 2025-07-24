//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include<stdio.h>

int moves = 0;

void towerOfHanoi(int n, char src, char dest, char temp) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        moves++;
        return;
    }

    towerOfHanoi(n-1, src, temp, dest);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    moves++;
    towerOfHanoi(n-1, temp, dest, src);
}

int main() {
    int num_disks;
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);

    printf("Tower of Hanoi steps for %d disks:\n", num_disks);
    towerOfHanoi(num_disks, 'A', 'C', 'B');

    printf("Total moves: %d", moves);
    return 0;
}