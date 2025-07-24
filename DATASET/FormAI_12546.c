//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from tower %c to tower %c\n", from, to);
        return;
    }

    hanoi(n-1, from, aux, to);

    printf("Move disk %d from tower %c to tower %c\n", n, from, to);

    hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("The number of disks has to be greater than 0.\n");
        return -1;
    }

    printf("Welcome to the Tower of Hanoi game!\n\n");

    printf("In the game, there are three towers labeled A, B, and C.\n");
    printf("You need to move %d disks from the tower A to tower C.\n", n);
    printf("However, you can only move one disk at a time and you can't put a larger disk on a smaller one.\n\n");

    printf("Let's see how many moves it takes you to complete the game! Good luck!\n\n");

    hanoi(n, 'A', 'C', 'B');
    printf("\nCongratulations! You have completed the game in the minimum number of moves possible!\n");

    return 0;
}