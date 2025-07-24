//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>

void towerOfHanoi(int n, char start, char end, char aux)
{
    if(n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    towerOfHanoi(n-1, start, aux, end);
    printf("Move disk %d from rod %c to rod %c\n", n, start, end);
    towerOfHanoi(n-1, aux, end, start);
}

int main()
{
    int n = 5;
    printf("Welcome to the Tower of Hanoi program!\n");
    printf("-------------------------------------\n");
    printf("Number of disks: %d\n", n);
    printf("Starting rod: A\n");
    printf("Ending rod: C\n");
    printf("-------------------------------------\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("-------------------------------------\n");
    printf("Thank you for using the program!\n");
    return 0;
}