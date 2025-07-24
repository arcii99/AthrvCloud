//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
/* Welcome to the Genius Tower of Hanoi Problem */

#include <stdio.h>

void move(int, char, char, char); // Function prototype

int main()
{
    int discs;

    printf("This is the Genius Tower of Hanoi Problem!\n\n");
    printf("Enter the number of discs: ");
    scanf("%d", &discs);

    printf("\nHere are the instructions to solve the puzzle:\n\n");
    move(discs,'A','C','B');

    printf("\nCongratulations! You have solved the puzzle!");

    return 0;
}

void move(int discs, char from_rod, char to_rod, char aux_rod)
{
    if (discs == 1) // Base case: Only one disc
    {
        printf("\nMove disc 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    move(discs - 1, from_rod, aux_rod, to_rod); // Move top n-1 discs from A to B using C as auxiliary
    printf("\nMove disc %d from rod %c to rod %c", discs, from_rod, to_rod); // Move last disc from A to C
    move(discs - 1, aux_rod, to_rod, from_rod); // Move top n-1 discs from B to C using A as auxiliary
}