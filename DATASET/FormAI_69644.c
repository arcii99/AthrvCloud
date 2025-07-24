//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

// This program solves the Tower of Hanoi problem using recursion
// The function takes in the number of disks, the starting peg, the destination peg and the auxiliary peg
void tower_of_hanoi(int disks, char start, char destination, char auxiliary) {
    if (disks == 1) { // base case with only 1 disk to move
        printf("Move disk 1 from peg %c to peg %c\n", start, destination); // move the disk to the destination peg
        return;
    }
    tower_of_hanoi(disks-1, start, auxiliary, destination); // recursive call to move n-1 disks from the start to the auxiliary peg
    printf("Move disk %d from peg %c to peg %c\n", disks, start, destination); // move the nth disk to the destination peg
    tower_of_hanoi(disks-1, auxiliary, destination, start); // recursive call to move n-1 disks from the auxiliary to the destination peg
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); // take in the number of disks from the user
    printf("The solution to the Tower of Hanoi problem for %d disks is:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B'); // solve the problem for n disks with pegs A, C and B
    return 0;
}