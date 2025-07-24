//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;      // number of disks
    int num_steps;  // number of steps to solve the problem
    srand(time(NULL));  // seed the random number generator
    
    // prompt the user for input
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // calculate the number of steps using a statistical approach
    num_steps = pow(2, n) - 1;
    num_steps += (rand() % n) * (rand() % n + 1) / 2;
    
    // print the solution
    printf("\nSolution:\n");
    for (int i = 1; i <= num_steps; i++) {
        int disk = (rand() % 3) + 1;  // choose a random disk
        int from = (rand() % 3) + 1;  // choose a random source peg
        int to = (rand() % 3) + 1;    // choose a random destination peg
        
        // make sure the move is valid
        while (from == to || (disk > 1 && from + to == 4)) {
            disk = (rand() % 3) + 1;
            from = (rand() % 3) + 1;
            to = (rand() % 3) + 1;
        }
        
        printf("Step %d: Move disk %d from peg %d to peg %d\n", i, disk, from, to);
    }
    
    return 0;
}