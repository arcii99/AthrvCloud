//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include<stdio.h>
#include<stdlib.h>

// Function to solve the Tower of Hanoi problem
void towers_of_hanoi(int n, char source, char destination, char auxiliary, int* moves)
{
    // Base case: if there is only one disk to move, move it from source to destination
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        (*moves)++;
        return;
    }

    // Move n-1 disks from source to auxiliary using destination tower as the auxiliary tower
    towers_of_hanoi(n-1, source, auxiliary, destination, moves);

    // Move the largest disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    (*moves)++;

    // Move the n-1 disks from auxiliary to destination using source tower as the auxiliary tower
    towers_of_hanoi(n-1, auxiliary, destination, source, moves);
}

int main()
{
    int n, moves=0;
    printf("Enter the number of disks in the Tower of Hanoi problem: ");
    scanf("%d", &n);

    // Solve the Tower of Hanoi problem
    towers_of_hanoi(n, 'A', 'C', 'B', &moves);

    printf("\nNumber of moves required to solve the Tower of Hanoi problem: %d", moves);
    return 0;
}