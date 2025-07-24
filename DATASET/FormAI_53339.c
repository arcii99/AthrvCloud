//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>

void moveDisks(int, char, char, char);

int main(void)
{
    int numDisks;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &numDisks);

    int i;
    for (i = 0; i < numDisks; i++)
    {
        printf("#");
    }
    printf("\n\n");

    moveDisks(numDisks, 'A', 'B', 'C');

    printf("\nYou solved the Tower of Hanoi with %d disks!\n", numDisks);
    
    return 0;
}

void moveDisks(int numDisks, char fromPeg, char toPeg, char sparePeg)
{
    if (numDisks == 1)
    {
        printf("Move disk 1 from peg %c to peg %c.\n", fromPeg, toPeg);
        return;
    }
    moveDisks(numDisks - 1, fromPeg, sparePeg, toPeg);
    printf("Move disk %d from peg %c to peg %c.\n", numDisks, fromPeg, toPeg);
    moveDisks(numDisks - 1, sparePeg, toPeg, fromPeg);
}