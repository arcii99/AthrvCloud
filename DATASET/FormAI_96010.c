//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>

void moveDisk(char from_rod, char to_rod, int disk_num) {
    printf("Move disk %d from rod %c to rod %c\n", disk_num, from_rod, to_rod);
}

void towerOfHanoi(int num_disks, char from_rod, char to_rod, char aux_rod) {
    if(num_disks == 1) {
        moveDisk(from_rod, to_rod, 1);
        return;
    }
    towerOfHanoi(num_disks-1, from_rod, aux_rod, to_rod);
    moveDisk(from_rod, to_rod, num_disks);
    towerOfHanoi(num_disks-1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    return 0;
}