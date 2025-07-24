//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>

void moveTower(int n, char source, char dest, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    moveTower(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    moveTower(n - 1, aux, dest, source);
}

int main()
{
    int n;
    char source = 'A', aux = 'B', dest = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    moveTower(n, source, dest, aux);

    return 0;
}