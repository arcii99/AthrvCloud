//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include<stdio.h>

void towerOfHanoi(int n, char source, char dest, char temp)
{
    if (n > 0)
    {
        towerOfHanoi(n-1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        towerOfHanoi(n-1, temp, dest, source);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n,'A', 'C', 'B');
    return 0;
}