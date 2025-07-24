//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: inquisitive
#include <stdio.h>

void move_disks(int, char, char, char);

int main() {
    int num_of_disks;

    printf("Welcome to the Tower of Hanoi problem!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &num_of_disks);

    printf("\n");
    move_disks(num_of_disks, 'A', 'C', 'B');

    return 0;
}

void move_disks(int num, char from_rod, char to_rod, char aux_rod) {
    if (num == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", from_rod, to_rod);
        return;
    }

    move_disks(num - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c.\n", num, from_rod, to_rod);
    move_disks(num - 1, aux_rod, to_rod, from_rod);
}