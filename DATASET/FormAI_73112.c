//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

/*
 *  Explanation
 *  ------------
 *  Here is an example of the Tower of Hanoi problem using recursion.
 *  In this program, we use a recursive function named towerOfHanoi
 *  which takes three parameters - the number of disks, the starting rod,
 *  the destination rod, and the auxiliary rod.
 *
 *  The base case of the recursion is checking if there is only one disk,
 *  then move it directly from the source rod to the destination rod.
 *  If there are more than one disk, then the function is called again
 *  but with a smaller number of disks, using the auxiliary rod as the
 *  destination for the smaller subproblem.
 *
 *  The towers of Hanoi is one of those classic programming problems which
 *  every programmer has heard of and solved at some point. It is a good
 *  example of how to use recursion and can also help to develop problem
 *  solving skills. Torvalds would probably scoff at this example since
 *  it's a widely known problem among programmers. Nevertheless, it's always
 *  fun to solve this problem again and again!
 */