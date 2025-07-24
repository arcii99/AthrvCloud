//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ada Lovelace
#include <stdio.h>

void towerOfHanoi(int n, char start, char end, char middle)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    towerOfHanoi(n-1, start, middle, end);
    printf("Move disk %d from rod %c to rod %c\n", n, start, end);
    towerOfHanoi(n-1, middle, end, start);
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}