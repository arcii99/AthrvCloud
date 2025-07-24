//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Touring
#include <stdio.h>

// Recursive function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char rod_from, char rod_auxiliary, char rod_to) {

    // If only one disk is present, move it and return
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", rod_from, rod_to);
        return;
    }

    // Move top n-1 discs from A to B using C as auxiliary
    tower_of_hanoi(n-1, rod_from, rod_to, rod_auxiliary);

    // Move remaining disk from A to C
    printf("Move disk %d from rod %c to rod %c\n", n, rod_from, rod_to);

    // Move n-1 discs from B to C using A as auxiliary
    tower_of_hanoi(n-1, rod_auxiliary, rod_from, rod_to);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // If the input is invalid
    if (n < 1) {
        printf("Invalid input! The number of disks should be greater than zero.\n");
        return 0;
    }

    // Display the steps to solve the Tower of Hanoi problem
    printf("Steps to solve the Tower of Hanoi problem with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}