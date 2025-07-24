//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>

void move(char from, char to)
{
    printf("Move a disk from %c to %c\n", from, to);
}

void towerOfHanoi(int n, char source, char temp, char destination)
{
    if (n == 1)
    {
        move(source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, temp);
    move(source, destination);
    towerOfHanoi(n - 1, temp, source, destination);
}

int main()
{
    int numDisks;
    printf("Welcome to the Tower of Hanoi problem!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &numDisks);
    if (numDisks > 0)
    {
        printf("\nYour moves for solving this puzzle are:\n");
        towerOfHanoi(numDisks, 'A', 'B', 'C');
    }
    else
    {
        printf("Invalid input. Number of disks must be greater than 0.\n");
        return 1;
    }
    return 0;
}