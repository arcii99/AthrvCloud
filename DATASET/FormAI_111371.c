//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

// This is my grateful Tower of Hanoi Problem example program!
// It's a great way to test your logic and problem-solving skills.

void moveDisk(char rodFrom, char rodTo, int diskNum);
void towerOfHanoi(int numDisks, char rodFrom, char rodAux, char rodTo);

int main() {
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Your goal is to move all the disks from rod A to rod C, using rod B as an auxiliary rod.\n");
    printf("Let's get started!\n\n");

    // Set the number of disks to play with
    int numDisks = 4;

    // Play the game!
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    printf("\nCongratulations! You've won the game!\n");
    printf("Thank you for playing. Have a great day!\n");

    return 0;
}

void moveDisk(char rodFrom, char rodTo, int diskNum) {
    printf("Move disk %d from rod %c to rod %c.\n", diskNum, rodFrom, rodTo);
}

void towerOfHanoi(int numDisks, char rodFrom, char rodAux, char rodTo) {
    if (numDisks == 1) {
        moveDisk(rodFrom, rodTo, 1);
        return;
    }

    towerOfHanoi(numDisks - 1, rodFrom, rodTo, rodAux);
    moveDisk(rodFrom, rodTo, numDisks);
    towerOfHanoi(numDisks - 1, rodAux, rodFrom, rodTo);
}