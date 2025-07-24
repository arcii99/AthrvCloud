//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

// declare variables for the number of disks and the number of moves
int num_disks;
int num_moves = 0;

// function prototype for recursive Tower of Hanoi function
void TowerOfHanoi(int, char, char, char);

int main() {
    // get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // call the Tower of Hanoi function with initial parameters
    TowerOfHanoi(num_disks, 'A', 'C', 'B');

    // print the number of moves required to solve the problem
    printf("Number of moves: %d\n", num_moves);

    return 0;
}

void TowerOfHanoi(int n, char source, char destination, char auxiliary) {
    // base case: if there is only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", n, source, destination);
        num_moves++;
    }
    // recursive case: move n-1 disks from source to auxiliary, then move the remaining disk from source to destination, then move n-1 disks from auxiliary to destination
    else {
        TowerOfHanoi(n-1, source, auxiliary, destination);
        printf("Move disk %d from %c to %c\n", n, source, destination);
        num_moves++;
        TowerOfHanoi(n-1, auxiliary, destination, source);
    }
}