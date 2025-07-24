//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>

void solve(int n, char from, char to, char aux) 
{
    if (n == 1) // Base case
	{
		printf("Move disk 1 from rod %c to rod %c\n", from, to);
		return;
	}
	
	// Move top n-1 disks from A to B, using C as auxiliary rod
    solve(n-1, from, aux, to);

    // Move remaining disks from A to C
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);

    // Move n-1 disks from B to C, using A as auxiliary rod
    solve(n-1, aux, to, from);
}

int main() 
{
    int n = 5; // Number of disks
    char A = 'A', B = 'B', C = 'C'; // The rods

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("In this game, you have %d disks and 3 rods (A, B, and C).\n", n);
    printf("The goal is to move all the disks from rod A to rod C, one at a time, without placing a larger disk on top of a smaller disk.\n");
    printf("Let's begin!\n\n");
	
    solve(n, A, C, B); // Call the recursive function
	
    printf("\nCongratulations! You have successfully completed the Tower of Hanoi game!\n");
    return 0;
}