//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from, char to, char aux);

int main()
{
    int disks;
    printf("How many disks do you want to use in the Tower of Hanoi problem: ");
    scanf("%d", &disks);

    hanoi(disks, 'A', 'B', 'C');

   return 0;
}

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from %c to %c", from, to);
        return;
    }

    hanoi(n-1, from, aux, to);
    printf("\n Move disk %d from %c to %c", n, from, to);
    hanoi(n-1, aux, to, from);
}