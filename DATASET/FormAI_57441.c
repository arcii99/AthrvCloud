//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>

void move(int, char, char, char);

int main() {
    int num_disks;
    char from = 'A', to = 'C', temp = 'B';

    printf("Enter the number of disks to transfer from %c to %c.\n", from, to);
    scanf("%d", &num_disks);

    move(num_disks, from, to, temp);

    return 0;
}

void move(int disk, char from_rod, char to_rod, char temp_rod) {
    if (disk == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);

        return;
    }

    move(disk - 1, from_rod, temp_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
    move(disk - 1, temp_rod, to_rod, from_rod);
}