//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>

void move(int numDisks, char source, char aux, char dest)
{
    if (numDisks == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    move(numDisks-1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", numDisks, source, dest);
    move(numDisks-1, aux, source, dest);
}

int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    move(numDisks, 'A', 'B', 'C');

    return 0;
}