//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

// Function to move disks from source to destination
void moveDisk(char source, char destination, int disk_number) {
    printf("Move disk %d from %c to %c\n", disk_number, source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void solveTowerOfHanoi(int number_of_disks, char source, char destination, char auxiliary) {
    if (number_of_disks == 1) {
        moveDisk(source, destination, 1);
        return;
    }
    solveTowerOfHanoi(number_of_disks - 1, source, auxiliary, destination);
    moveDisk(source, destination, number_of_disks);
    solveTowerOfHanoi(number_of_disks - 1, auxiliary, destination, source);
}

int main() {
    // Initializing the number of disks
    int number_of_disks = 4;

    // Defining the towers
    char tower_a = 'A', tower_b = 'B', tower_c = 'C';

    // Solving the Tower of Hanoi problem
    solveTowerOfHanoi(number_of_disks, tower_a, tower_c, tower_b);

    return 0;
}