//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>

void hanoi(int n, char source, char destination, char helper)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    hanoi(n-1, source, helper, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(n-1, helper, destination, source);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nHere's the sequence of moves:\n");
    hanoi(n, 'A', 'C', 'B');

    return 0;
}