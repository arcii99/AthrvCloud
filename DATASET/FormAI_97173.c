//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void towers_of_hanoi(int n, char A, char B, char C);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towers_of_hanoi(n, 'A', 'B', 'C');

    return 0;
}

void towers_of_hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("Move disk %d from pole %c to pole %c\n", n, A, C);
        return;
    }

    towers_of_hanoi(n - 1, A, C, B);
    printf("Move disk %d from pole %c to pole %c\n", n, A, C);
    towers_of_hanoi(n - 1, B, A, C);
}