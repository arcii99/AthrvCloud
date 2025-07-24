//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function to move disks from one pole to another pole
void moveDisk(char fromPole, char toPole, int disk)
{
    printf("Move disk %d from %c to %c\n", disk, fromPole, toPole);
}

// Recursive function to solve Tower of Hanoi problem
void solveTowerOfHanoi(int disks, char source, char auxiliary, char destination){
    if (disks <= 0) // Base case
        return;

    // Move top n-1 disks from source pole to auxiliary pole
    solveTowerOfHanoi(disks - 1, source, destination, auxiliary);

    // Move remaining disk from source pole to destination pole
    moveDisk(source, destination, disks);

    // Move n-1 disks from auxiliary pole to destination pole
    solveTowerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main()
{
    int disks = 4; // Number of disks
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("In this game, you have to move all the disks from the source pole to the destination pole\n");
    printf("You can only move one disk at a time and you cannot place a larger disk on a smaller disk\n");
    printf("Let's begin!\n\n");

    printf("Initially, the disks are arranged in decreasing order, with the largest disk at the bottom\n");
    printf("Source pole: A\t\tAuxiliary pole: B\t\tDestination pole: C\n\n");

    printf("The sequence of moves to be followed in order to solve the game is: \n");
    solveTowerOfHanoi(disks, source, auxiliary, destination);
    printf("\n");

    printf("Congratulations, you have solved the Tower of Hanoi game!\n");

    return 0;
}