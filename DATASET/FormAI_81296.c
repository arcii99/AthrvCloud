//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Touring
#include <stdio.h>

void hanoi(int, char, char, char);

int main()
{
    int numDiscs;
    printf("Enter the number of discs: ");
    scanf("%d", &numDiscs);
    hanoi(numDiscs, 'A', 'B', 'C');
    return 0;
}

void hanoi(int num, char source, char aux, char dest)
{
    if(num == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }
    hanoi(num - 1, source, dest, aux);
    printf("Move disk %d from rod %c to rod %c\n", num, source, dest);
    hanoi(num - 1, aux, source, dest);
}