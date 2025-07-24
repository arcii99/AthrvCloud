//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>

// Function to perform the recursive tower of hanoi algorithm
void towerOfHanoi(int numDisks, char source, char aux, char dest)
{
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    towerOfHanoi(numDisks - 1, source, dest, aux);

    printf("Move disk %d from %c to %c\n", numDisks, source, dest);

    towerOfHanoi(numDisks - 1, aux, source, dest);
}

int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    printf("\n");

    // Ensure there are enough disks to run the program
    if (numDisks < 1)
    {
        printf("The tower of hanoi problem requires at least one disk to work\n");
        return 0;
    }

    // Run the recursive algorithm to solve the tower of hanoi problem
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}