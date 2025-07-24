//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>

/* Function to move a disk from one peg to another */
void move_disk(int start, int end) {
    printf("Move disk from peg %d to peg %d\n", start, end);
}

/* Recursive function to solve the tower of Hanoi problem */
void tower_of_hanoi(int disks, int start, int end, int temp) {
    if (disks == 1) {
        move_disk(start, end);
        return;
    }
    tower_of_hanoi(disks - 1, start, temp, end);
    move_disk(start, end);
    tower_of_hanoi(disks - 1, temp, end, start);
}

int main() {
    int disks, start = 1, end = 3, temp = 2;

    printf("Enter the number of disks to solve the Tower of Hanoi problem: ");
    scanf("%d", &disks);

    printf("\nSteps to move all the disks from peg %d to peg %d:\n", start, end);
    tower_of_hanoi(disks, start, end, temp);
    return 0;
}