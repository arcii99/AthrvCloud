//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

void move(int n, char source, char temp, char dest);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    return 0;
}

void move(int n, char source, char temp, char dest)
{
    if(n == 1)
    {
        printf("Move disk %d from pole %c to pole %c\n", n, source, dest);
        return;
    }
    move(n-1, source, dest, temp);
    printf("Move disk %d from pole %c to pole %c\n", n, source, dest);
    move(n-1, temp, source, dest);
}