//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>

// Function prototype
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod);

// Main function
int main() {
    int n = 3; // Number of disks
    char fromRod = 'A', toRod = 'C', auxRod = 'B'; // Rods

    // Function call for Tower of Hanoi
    towerOfHanoi(n, fromRod, toRod, auxRod);

    return 0;
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) { // Base case
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    // Recursive case
    towerOfHanoi(n-1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n-1, auxRod, toRod, fromRod);
}