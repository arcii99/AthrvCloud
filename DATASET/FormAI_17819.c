//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>

void hanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", A, C);
        return;
    }
    hanoi(n - 1, A, B, C);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    hanoi(n - 1, B, C, A);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nThe steps to solve the Tower of Hanoi with %d disks are:\n\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}