//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

void towerOfHanoi(int noOfDisks, char towerSource, char towerAuxiliary, char towerDestination)
{
    if (noOfDisks == 1)
    {
        printf("Move disk %d from tower %c to tower %c\n", noOfDisks, towerSource, towerDestination);
        return;
    }
    towerOfHanoi(noOfDisks - 1, towerSource, towerDestination, towerAuxiliary);
    printf("Move disk %d from tower %c to tower %c\n", noOfDisks, towerSource, towerDestination);
    towerOfHanoi(noOfDisks - 1, towerAuxiliary, towerSource, towerDestination);
}

int main()
{
    int noOfDisks;
    char towerSource = 'A', towerAuxiliary = 'B', towerDestination = 'C';

    printf("Welcome to the Tower of Hanoi Problem...\n");
    printf("Enter the number of disks : ");
    scanf("%d", &noOfDisks);

    printf("\nSolution Steps:\n");
    towerOfHanoi(noOfDisks, towerSource, towerAuxiliary, towerDestination);

    printf("\nThank You for using the program!\n");
    return 0;
}