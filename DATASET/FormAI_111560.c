//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void moveTower(int, char, char, char); // function prototype

int main()
{
    int numDisks;
    
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    
    printf("\nThe sequence of moves involved in the Tower of Hanoi problem with %d disks are:\n", numDisks);
    moveTower(numDisks, 'A', 'B', 'C'); // function call
    
    return 0;
}

void moveTower(int numDisks, char startPeg, char endPeg, char tempPeg)
{
    if (numDisks == 1) // base case
    {
        printf("%c -> %c\n", startPeg, endPeg);
        return;
    }
    moveTower(numDisks - 1, startPeg, tempPeg, endPeg); // recursive call for sub-problem
    printf("%c -> %c\n", startPeg, endPeg); // move one disk from start peg to end peg
    moveTower(numDisks - 1, tempPeg, endPeg, startPeg); // recursive call for sub-problem
}