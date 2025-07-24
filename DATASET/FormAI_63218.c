//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tower_of_hanoi(int n, char from_rod[], char to_rod[], char aux_rod[])
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %s to rod %s\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %s to rod %s\n", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 4;
    char from_rod[] = "A";
    char to_rod[] = "C";
    char aux_rod[] = "B";
    printf("Welcome to Tower of Hanoi!\n");
    printf("In this game, you have to move all the disks from rod A to rod C using rod B.\n");
    printf("The rules are simple, you can only move one disk at a time and a larger disk cannot be placed on a smaller disk.\n\n");
    printf("Please enter the number of disks you want to play with (minimum 3): ");
    scanf("%d", &n);
    printf("\n\n");
    if (n < 3)
    {
        printf("Sorry, minimum number of disks required is 3.\n");
        return 1;
    }
    printf("You have chosen to play with %d disks!\n\n", n);
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);
    printf("\n\nCongratulations, you have successfully completed the game!\n\n");
    return 0;
}