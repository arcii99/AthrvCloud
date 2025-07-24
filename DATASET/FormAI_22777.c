//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include<stdio.h>

void tower_of_hanoi(int disks, char source, char destination, char auxillary)
{
    if(disks == 1) // Base case, one disk to move
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    tower_of_hanoi(disks - 1, source, auxillary, destination); // Move disks n-1 from source to auxillary using destination as the auxillary
    printf("Move disk %d from %c to %c\n", disks, source, destination); // Move the largest disk from source to destination
    tower_of_hanoi(disks - 1, auxillary, destination, source); // Move disks n-1 from auxillary to destination using source as the auxillary
}

int main()
{
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    printf("The solution for %d disks is:\n", disks);
    tower_of_hanoi(disks, 'A', 'C', 'B'); // Start the recursion with source as A, destination as C and auxillary as B
    return 0;
}