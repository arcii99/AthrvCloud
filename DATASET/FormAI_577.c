//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void moveDisks(int, char, char, char);

int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    moveDisks(numDisks, 'A', 'C', 'B');
    return 0;
}

void moveDisks(int numDisks, char source, char dest, char aux)
{
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    moveDisks(numDisks - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", numDisks, source, dest);
    moveDisks(numDisks - 1, aux, dest, source);
}