//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>

void move(int discs, char from_peg, char to_peg, char using_peg)
{
    if(discs == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    
    move(discs-1, from_peg, using_peg, to_peg);
    printf("Move disk %d from peg %c to peg %c\n", discs, from_peg, to_peg);
    move(discs-1, using_peg, to_peg, from_peg);
}

int main()
{
    int num_discs;
    printf("Enter the number of discs: ");
    scanf("%d", &num_discs);
    
    move(num_discs, 'A', 'C', 'B');
    
    return 0;
}