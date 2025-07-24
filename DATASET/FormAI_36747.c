//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int numberOfMoves = 0;

void move(char start, char end) {
    printf("Move disk from %c to %c\n", start, end);
    numberOfMoves++;
}

void towerOfHanoi(int numDisks, char start, char end, char middle) {
    if(numDisks == 1) {
        move(start, end);
        return;
    }
    towerOfHanoi(numDisks-1, start, middle, end);
    move(start, end);
    towerOfHanoi(numDisks-1, middle, end, start);
}

int main() {
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("In this game, you will be given a setup of three pegs\n");
    printf("One filled with disks of varying sizes, arranged in decreasing order\n");
    printf("Your goal is to move the entire stack to another peg, following these simple rules:\n");
    printf("1. Only one disk can be moved at a time\n");
    printf("2. Each move consists of taking the upper disk from one of the pegs\n");
    printf("   and placing it on top of another peg or on an empty peg\n");
    printf("3. No larger disk may be placed on top of a smaller disk\n\n");

    printf("Let's get started!\n\n");

    int numDisks;
    char start = 'A', end = 'B', middle = 'C';

    printf("Enter the number of disks in the starting peg: ");
    scanf("%d", &numDisks);

    towerOfHanoi(numDisks, start, end, middle);

    printf("\nCongratulations! You have successfully moved the tower!\n");
    printf("It took you %d moves to complete the game.\n", numberOfMoves);

    printf("\nThanks for playing the Tower of Hanoi game!\n");

    return 0;
}