//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to perform Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If only 1 disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    tower_of_hanoi(n-1, source, auxiliary, destination);

    // Move the remaining disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n-1, auxiliary, destination, source);
}

// Driver code
int main() {
    int n = 3; // Number of disks
    tower_of_hanoi(n, 'A', 'C', 'B'); // A, B and C are the 3 rods
    return 0;
}