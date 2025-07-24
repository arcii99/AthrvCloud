//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

void moveDisk(int n, char source, char dest, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }
    moveDisk(n - 1, source, aux, dest);
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    moveDisk(n - 1, aux, dest, source);
}

int main()
{
    int n = 3; // number of disks
    moveDisk(n, 'A', 'C', 'B'); // calling the function to move the disks
    return 0;
}