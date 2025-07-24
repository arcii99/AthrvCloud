//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void moveDisks(int, char, char, char);
int getDiskNumber();

int main()
{
    system("clear");
    printf("\n\tWelcome to the Tower of Hanoi Apocalypse!\n\n");

    const int numDisks = getDiskNumber();

    printf("\n\tNumber of disks: %d\n", numDisks);
    printf("\n\tLet the game begin!\n\n");

    moveDisks(numDisks, 'A', 'C', 'B');

    printf("\n\tCongratulations, you have saved humanity!");

    return 0;
}

//Recursively moves the disks
void moveDisks(int n, char from, char to, char temp)
{
    if(n <= 0)
        return;

    moveDisks(n-1, from, temp, to);
    printf("\tMove disk %d from peg %c to peg %c\n", n, from, to);
    moveDisks(n-1, temp, to, from);
}

//Gets the number of disks for the game
int getDiskNumber()
{
    int num;

    do
    {
        printf("\tEnter the number of disks (minimum 3): ");
        scanf("%d", &num);
    }
    while(num < 3);

    return num;
}