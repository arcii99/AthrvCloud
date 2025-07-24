//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
}

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if(num_disks < 1)
    {
        printf("Invalid input");
        exit(0);
    }
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(num_disks, 'A', 'C', 'B');
    return 0;
}