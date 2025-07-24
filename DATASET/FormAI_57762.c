//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

// function to solve tower of hanoi problem
void tower_of_hanoi(int n, char rod_from, char rod_aux, char rod_to) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", rod_from, rod_to);
        return;
    }
    tower_of_hanoi(n - 1, rod_from, rod_to, rod_aux);
    printf("Move disk %d from rod %c to rod %c\n", n, rod_from, rod_to);
    tower_of_hanoi(n - 1, rod_aux, rod_from, rod_to);
}

int main() {
    int n = 3;  // number of disks
    printf("Welcome to the Tower of Hanoi game!\n");

    printf("The goal of the game is to move all the disks from one rod to another, following these rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. A disk can only be moved if it is the uppermost disk on one of the rods.\n");
    printf("3. No disk can be placed on top of a smaller disk.\n\n");

    printf("Press any key to continue...");
    getchar();

    printf("\nThe game begins with %d disks on rod A.\n", n);
    printf("Let's get started!\n\n");

    tower_of_hanoi(n, 'A', 'B', 'C');

    printf("Congratulations! You have successfully completed the Tower of Hanoi game!\n");

    return 0;
}