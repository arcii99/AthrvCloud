//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int move(int n, char start, char end, char temp) {

    if (n == 0) {
        return;
    } 

    move(n - 1, start, temp, end);

    printf("Move disk %d from %c to %c\n", n, start, end);

    move(n - 1, temp, end, start);

    return;
}

int main() {

    int numDisks;

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks would you like to play with? (Please enter an integer)\n");

    if (scanf("%d", &numDisks) < 1) {
        printf("Invalid input. Please run the program again with a valid integer input.\n");
        return 0;
    }

    printf("Great! Let's play with %d disks.\n", numDisks);
    printf("Here are the rules: You can only move one disk at a time to another peg, and you can only move a disk that is on top of a stack of disks. A larger disk cannot be placed on a smaller disk.\n");

    printf("Starting game...\n");

    move(numDisks, 'A', 'C', 'B');

    printf("Congratulations! You have successfully completed the game!\n");

    return 0;
}