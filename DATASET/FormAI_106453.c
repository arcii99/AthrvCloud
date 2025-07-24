//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include<stdio.h>

void towers_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main()
{
    int n = 3;  // number of discs
    towers_of_hanoi(n, 'A', 'C', 'B');  // A, B and C are the rods
    return 0;
}

void towers_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // base case
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towers_of_hanoi(n-1, from_rod, aux_rod, to_rod); // recursive call to move n-1 discs to aux_rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod); // move remaining disc to to_rod
    towers_of_hanoi(n-1, aux_rod, to_rod, from_rod); // recursive call to move n-1 discs from aux_rod to to_rod
}