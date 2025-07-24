//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

/**
 * This program solves the 'Tower of Hanoi' problem with three towers and four discs using recursion.
 * It prints the steps required to move all the discs from the first tower to the third tower.
 */

void moveDisc(int disc, char from, char to)
{
    printf("Move disc %d from %c to %c\n", disc, from, to);
}

void moveTower(int height, char from, char to, char aux)
{
    if (height == 1)
    {
        moveDisc(height, from, to);
    }
    else
    {
        moveTower(height - 1, from, aux, to);
        moveDisc(height, from, to);
        moveTower(height - 1, aux, to, from);
    }
}

int main()
{
    printf("Welcome to the Tower of Hanoi!\n\n");
    printf("Instructions:\n");
    printf("- There are three towers: A, B, and C.\n");
    printf("- There are four discs, each of a different size.\n");
    printf("- The objective is to move all the discs from tower A to tower C using the following rules:\n");
    printf("  1. Only one disc can be moved at a time.\n");
    printf("  2. A disc cannot be placed on top of a smaller disc.\n\n");

    printf("Here are the steps required to solve the problem:\n");
    moveTower(4, 'A', 'C', 'B');

    printf("\nCongratulations! You have solved the Tower of Hanoi.\n");
    return 0;
}