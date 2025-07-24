//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
// Tower of Hanoi Problem Example Program in a Protected Style
// Language: C
#include <stdio.h>

void move(int n, char from_peg, char to_peg, char aux_peg)
{
    // base case
    if (n == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", from_peg, to_peg);
        return;
    }
    // recursive case
    move(n-1, from_peg, aux_peg, to_peg);
    printf("\n Move disk %d from peg %c to peg %c", n, from_peg, to_peg);
    move(n-1, aux_peg, to_peg, from_peg);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid input");
    }
    else
    {
        printf("\n The moves are: \n");
        move(n, 'A', 'C', 'B');
    }
    return 0;
}