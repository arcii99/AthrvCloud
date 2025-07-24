//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: happy
#include <stdio.h>

void move(int, char, char, char);
int countMoves(int);

int main() {
    int discs = 5;
    int numMoves = countMoves(discs);
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("In this game you must move %d discs from peg A to peg C using peg B.\n", discs);
    printf("You can only move one disc at a time and you can never place a larger disc on top of a smaller disc.\n");
    printf("You will need to make %d moves to complete the game. Are you ready? Let's go!\n\n", numMoves);

    move(discs, 'A', 'B', 'C');

    printf("\n\nCongratulations! You have completed the game in %d moves. You are a Tower of Hanoi champion!", numMoves);

    return 0;
}

void move(int discs, char from, char to, char temp) {
    if (discs == 1) {
        printf("Move disc 1 from peg %c to peg %c.\n", from, to);
        return;
    }
    move(discs - 1, from, temp, to);
    printf("Move disc %d from peg %c to peg %c.\n", discs, from, to);
    move(discs - 1, temp, to, from);
}

int countMoves(int discs) {
    if (discs == 1) {
        return 1;
    }
    return 2 * countMoves(discs - 1) + 1;
}