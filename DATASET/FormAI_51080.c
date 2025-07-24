//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>

void hanoi(int n, char from, char to, char temp);

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');

    return 0;
}

void hanoi(int n, char from, char to, char temp)
{
    if(n==1)
    {
        printf("%c -> %c\n", from, to);
        return;
    }

    hanoi(n-1, from, temp, to);
    printf("%c -> %c\n", from, to);
    hanoi(n-1, temp, to, from);
}