//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

// function to move a disk from source pole to destination pole
void moveDisk(int sourcePole, int destinationPole) {
    printf("Move the disk from pole %d to pole %d\n", sourcePole, destinationPole);
}

// function to generate all possible moves for n number of disks
void generateMoves(int n, int sourcePole, int destinationPole, int temporaryPole) {
    if (n == 0) return; // base case

    // move upper n-1 disks from source pole to temporary pole
    generateMoves(n-1, sourcePole, temporaryPole, destinationPole);

    // move remaining disk from source pole to destination pole
    moveDisk(sourcePole, destinationPole);

    // move upper n-1 disks from temporary pole to destination pole
    generateMoves(n-1, temporaryPole, destinationPole, sourcePole);
}

int main() {
    int n;
    
    printf("Welcome to the Tower of Hanoi problem solver!\n\n");
    printf("How many disks do you want to use? (Enter a positive integer greater than 0): ");
    
    // get user input for number of disks
    scanf("%d", &n);

    // check if the input is valid
    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer greater than 0.\n");
        return 0;
    }

    // generate all possible moves for n disks from pole A to pole C using pole B as temporary
    generateMoves(n, 1, 3, 2);

    // celebrate the successful completion of the puzzle!
    printf("\nCongratulations! You have solved the Tower of Hanoi problem with %d disks!\n", n);

    return 0;
}