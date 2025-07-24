//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>

void towerOfHanoi(int, char, char, char);

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are the name of rods.

    return 0;
}

/*
* Main recursive function for tower of hanoi.
* This function takes the number of disks, src, dest and auxilary rod as argument and prints the moves required to solve the problem.
*/
void towerOfHanoi(int n, char sourceRod, char destinationRod, char auxiliaryRod)
{
    /*
    * Base Condition: If only 1 disk is present then terminate the recursive function and print the move from source to destination rod.
    */
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c.\n", sourceRod, destinationRod);
        return;
    }

    /*
    * Recursive call: Move n-1 disks from source to auxiliary rod.
    */
    towerOfHanoi(n-1, sourceRod, auxiliaryRod, destinationRod);

    /*
    * Move last disk from source to destination rod.
    */
    printf("Move disk %d from %c to %c.\n", n, sourceRod, destinationRod);

    /*
    * Recursive call: Move previously moved n-1 disks from auxiliary to destination rod.
    */
    towerOfHanoi(n-1, auxiliaryRod, destinationRod, sourceRod);
}