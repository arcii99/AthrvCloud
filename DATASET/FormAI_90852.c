//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

// Function to move discs between towers
void move(int from_tower, int to_tower)
{
    printf("Move disc from tower %d to tower %d\n", from_tower, to_tower);
}

// Function to solve Tower of Hanoi Problem using recursion
void solve_tower_hanoi(int num_discs, int from_tower, int to_tower, int aux_tower)
{
    if (num_discs == 1)
    {
        move(from_tower, to_tower);
        return;
    }
    
    solve_tower_hanoi(num_discs - 1, from_tower, aux_tower, to_tower); // Move n-1 discs from A to B using C as aux tower
    move(from_tower, to_tower); // Move largest disc from A to C
    solve_tower_hanoi(num_discs - 1, aux_tower, to_tower, from_tower); // Move n-1 discs from B to C using A as aux tower
}

int main()
{
    int num_discs;
    
    printf("Welcome to the Tower of Hanoi problem solver!\n");
    printf("Please enter the number of discs: ");
    scanf("%d", &num_discs);
    
    if (num_discs <= 0)
    {
        printf("Invalid input. Number of discs should be greater than zero.\n");
        return 1;
    }
    
    printf("\nSolving Tower of Hanoi problem with %d discs...\n\n", num_discs);
    solve_tower_hanoi(num_discs, 1, 3, 2);
    
    printf("\nCongratulations, the Tower of Hanoi problem has been solved!\n");
    
    return 0;
}