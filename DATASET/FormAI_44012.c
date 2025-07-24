//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to implement Tower of Hanoi problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // Base condition for recursion
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); // Moving n-1 disks from 'from_rod' to 'aux_rod'
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); // Moving n-1 disks from 'aux_rod' to 'to_rod'
}

int main()
{
    int n = 0;

    // Take user input for total number of disks
    printf("Enter total number of disks: ");
    scanf("%d", &n);
    printf("\n");

    // Call the recursive function to implement Tower of Hanoi
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");

    return 0;
}