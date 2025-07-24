//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void tower(int n, int A, int B, int C)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    tower(n-1, A, C, B);
    printf("Move disk %d from %c to %c\n", n, A, C);
    tower(n-1, B, A, C);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Invalid input.\n");
        exit(0);
    }
    tower(n, 'A', 'B', 'C');
    return 0;
}