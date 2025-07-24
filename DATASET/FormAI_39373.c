//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>

// This function takes the number of disks, the start tower, the end tower, and the auxiliary tower as input
void tower_of_hanoi(int n, char start_tower, char end_tower, char aux_tower) {
    // If there is only one disk, move it from start tower to the end tower
    if (n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", start_tower, end_tower);
        return;
    }

    // Move n - 1 disks from start tower to the auxiliary tower
    tower_of_hanoi(n - 1, start_tower, aux_tower, end_tower);

    // Move the nth disk from start tower to the end tower
    printf("Move disk %d from tower %c to tower %c\n", n, start_tower, end_tower);

    // Move the n - 1 disks from auxiliary tower to end tower
    tower_of_hanoi(n - 1, aux_tower, end_tower, start_tower);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input!\n");
        return 0;
    }

    // Calculate the number of moves required to solve the Tower of Hanoi problem
    int moves = (1 << n) - 1;

    printf("Number of moves required: %d\n", moves);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}