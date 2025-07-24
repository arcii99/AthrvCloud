//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

/* Define the move function to move a disc from one peg to another */
void move(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }
    
    /* Move top n-1 disks from A to B using C as auxiliary */
    move(n-1, from, temp, to);
    
    /* Move remaining last disk from A to C */
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    
    /* Move n-1 disks from B to C using A as auxiliary */
    move(n-1, temp, to, from);
}

/* The main function */
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    /* Ensure the input is not too large */
    if (n > 8)
    {
        printf("That's too many disks! Aborting...\n");
        return 0;
    }
    
    printf("Solving the Tower of Hanoi problem for %d disks...\n", n);
    move(n, 'A', 'C', 'B');
    
    /* We're done! */
    printf("All done!\n");
    return 0;
}