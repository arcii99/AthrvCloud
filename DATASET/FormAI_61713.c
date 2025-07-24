//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>

void towerOfHanoi(int numDisks, char sourcePole, char destinationPole, char auxiliaryPole, int* moves)
{
    if(numDisks == 1)
    {
        printf("Move disk 1 from pole %c to pole %c\n", sourcePole, destinationPole);
        (*moves)++;
        return;
    }
    towerOfHanoi(numDisks-1, sourcePole, auxiliaryPole, destinationPole, moves);
    printf("Move disk %d from pole %c to pole %c\n", numDisks, sourcePole, destinationPole);
    (*moves)++;
    towerOfHanoi(numDisks-1, auxiliaryPole, destinationPole, sourcePole, moves);
}

int main()
{
    int numDisks, moves = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    fflush(stdin);
    if(numDisks < 1)
    {
        printf("Invalid input! Number of disks should be a positive integer.\n");
        return 1;
    }
    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n", numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B', &moves);
    printf("Total moves: %d\n", moves);
    return 0;
}