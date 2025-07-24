//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>

int step = 0;

void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1) 
    {
        printf("Step %d: Move disk 1 from rod %c to rod %c\n", ++step, from, to);
        return;
    }

    tower_of_hanoi(n-1, from, aux, to);
    printf("Step %d: Move disk %d from rod %c to rod %c\n", ++step, n, from, to);
    tower_of_hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}