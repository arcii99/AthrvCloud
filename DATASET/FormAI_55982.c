//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

void move(char fromRod, char toRod, int disk);

void tower_of_hanoi(int num_disks, char from_rod, char to_rod, char spare_rod) {
    if (num_disks == 1) {
        move(from_rod, to_rod, num_disks);
    }
    else {
        tower_of_hanoi(num_disks - 1, from_rod, spare_rod, to_rod);
        move(from_rod, to_rod, num_disks);
        tower_of_hanoi(num_disks - 1, spare_rod, to_rod, from_rod);
    }
}

void move(char fromRod, char toRod, int disk) {
    printf("Move disk %d from Rod %c to Rod %c\n", disk, fromRod, toRod);
}

int main() {
    int num_disks = 3;
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}