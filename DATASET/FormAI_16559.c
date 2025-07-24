//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>

void towerOfHanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }
    towerOfHanoi(n-1, A, B, C);
    printf("Move disk %d from %c to %c\n", n, A, C);
    towerOfHanoi(n-1, B, C, A);
}

int main()
{
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d",&disks);
    printf("\n");
    towerOfHanoi(disks, 'A', 'C', 'B');
    return 0;
}