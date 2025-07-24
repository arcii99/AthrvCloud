//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

// Define global variables to keep track of moves and number of disks
int moves = 0;
int numDisks;

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(int numDisks, char rodFrom, char rodTo, char rodAux) {
    // Base case: if there is only one disk to move, simply move it from rodFrom to rodTo
    if (numDisks == 1) {
        moves++;
        printf("%d. Move disk 1 from rod %c to rod %c\n", moves, rodFrom, rodTo);
        return;
    }
    
    // Recursive case: move the top n-1 disks from rodFrom to rodAux, then move the remaining disk from rodFrom to rodTo, and finally move the n-1 disks from rodAux to rodTo
    towerOfHanoi(numDisks-1, rodFrom, rodAux, rodTo);
    moves++;
    printf("%d. Move disk %d from rod %c to rod %c\n", moves, numDisks, rodFrom, rodTo);
    towerOfHanoi(numDisks-1, rodAux, rodTo, rodFrom);
}

int main() {
    // Ask user for the number of disks to solve the Tower of Hanoi problem for
    printf("Welcome to the Tower of Hanoi solver!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &numDisks);
    
    // Solve the Tower of Hanoi problem
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    
    // Output the number of moves needed to solve the problem
    printf("It took %d moves to solve the Tower of Hanoi problem for %d disks.\n", moves, numDisks);
    
    return 0;
}