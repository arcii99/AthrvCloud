//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>

// Define a function for the exciting recursive solution to Tower of Hanoi Problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // Base case - when only one disk is to be moved
    {
        printf("\nWoohoo! Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    
    // Recursively move disks from the source to the destination peg
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\nGo, go, go! Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    
    // Recursively move disks from the auxiliary to the destination peg
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int num_disks; // Declare the number of disks that will be used in the game
    
    printf("Are you ready for the exciting Tower of Hanoi game?\n");
    printf("Enter the number of disks you wish to start with: ");
    scanf("%d", &num_disks);
    
    // Make sure the player enters a valid number of disks
    while(num_disks < 1 || num_disks > 10)
    {
        printf("Oops, that's not a valid number! Please enter a number between 1 and 10: ");
        scanf("%d", &num_disks);
    }
    
    printf("\nLet the game begin!!\n");
    towerOfHanoi(num_disks, 'A', 'C', 'B'); // Call the exciting recursive function
    
    printf("\nThe game is over. Hope you had fun! :)");
    return 0;
}