//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>

// Recursive function for solving Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    printf("Welcome to the Tower of Hanoi problem solver!\n\n");
    printf("This program will show you the steps to solve the problem given the number of disks you want to use.\n");
    printf("Please enter the number of disks you want to use: ");
    int n;
    scanf("%d", &n);
    printf("\n");

    printf("Here are the steps to solve the problem with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');

    printf("\nCongratulations, the problem has been solved!");
    return 0;
}