//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>

void towerOfHanoi(int n, char source, char aux, char dest)
{
    if (n == 1)
    {
        printf("%c -> %c\n", source, dest);
        return;
    }
    towerOfHanoi(n-1, source, dest, aux);
    printf("%c -> %c\n", source, dest);
    towerOfHanoi(n-1, aux, source, dest);
}

int main()
{
    int n = 3;  // number of disks
    char source = 'A', aux = 'B', dest = 'C';  // peg names

    printf("Instructions for Tower of Hanoi problem with %d disks:\n\n", n);
    towerOfHanoi(n, source, aux, dest);

    return 0;
}