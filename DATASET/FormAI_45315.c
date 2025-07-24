//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main()
{
    int numOfDisks;
    printf("Enter the number of disks in the Tower of Hanoi problem: ");
    scanf("%d", &numOfDisks);
    if (numOfDisks < 1)
    {
        printf("Invalid number of disks. Please enter a positive integer greater than 0.\n");
        return -1;
    }
    printf("The solution to the Tower of Hanoi problem for %d disks is:\n", numOfDisks);
    towerOfHanoi(numOfDisks, 'A', 'C', 'B');
    return 0;
}