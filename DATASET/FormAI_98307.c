//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int* moves)
{
    if (n == 1)
    {
        (*moves)++;
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod, moves);
    (*moves)++;
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod, moves);
}

int main()
{
    int n, moves = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nEnergy levels are high! Ready to solve Tower of Hanoi problem!\n");
    printf("Initiating the game...\n");
    printf("**********************\n");

    towerOfHanoi(n, 'A', 'C', 'B', &moves);

    printf("**********************\n");
    printf("Game over in %d moves! Congratulations on solving the Tower of Hanoi problem!\n", moves);

    return 0;
}