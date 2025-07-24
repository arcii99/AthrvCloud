//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>

void move_disk(int, char, char, char);
void tower_of_hanoi(int, char, char, char);

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    tower_of_hanoi(num_disks, 'A', 'B', 'C');
    return 0;
}

void move_disk(int disk_num, char from, char to, char aux) {
    printf("Move disk %d from %c to %c\n", disk_num, from, to);
}

void tower_of_hanoi(int num_disks, char from, char to, char aux) {
    if (num_disks == 1) {
        move_disk(num_disks, from, to, aux);
        return;
    }
    tower_of_hanoi(num_disks-1, from, aux, to);
    move_disk(num_disks, from, to, aux);
    tower_of_hanoi(num_disks-1, aux, to, from);
}