//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int inputNumDisks() {
    int numDisks = 0;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Please enter the number of disks you would like to play with: ");
    scanf("%d", &numDisks);
    while(numDisks <= 0) {
        printf("Invalid input. Number of disks must be greater than 0.\n");
        printf("Please enter the number of disks you would like to play with: ");
        scanf("%d", &numDisks);
    }
    return numDisks;
}

void moveDisk(char fromPeg, char toPeg, int diskNum) {
    printf("Move disk %d from %c to %c\n", diskNum, fromPeg, toPeg);
}

void playGame(int numDisks, char fromPeg, char toPeg, char auxPeg) {
    if(numDisks == 1) {
        moveDisk(fromPeg, toPeg, numDisks);
        return;
    }
    playGame(numDisks-1, fromPeg, auxPeg, toPeg);
    moveDisk(fromPeg, toPeg, numDisks);
    playGame(numDisks-1, auxPeg, toPeg, fromPeg);
}

int main() {
    int numDisks = inputNumDisks();
    playGame(numDisks, 'A', 'C', 'B');
    printf("Congratulations, you have solved the Tower of Hanoi!\n");
    return 0;
}