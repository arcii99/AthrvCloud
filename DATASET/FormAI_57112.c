//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>

// Function to recursively move disks from one peg to another
void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg)
{
    if (n == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main()
{
    int num_disks = 4; // Change this to any positive integer
    printf("Solving Tower of Hanoi for %d disks...\n", num_disks);
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    return 0;
}