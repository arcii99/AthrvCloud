//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

void print_star(int n);
void print_spaces(int n);

int main()
{
    int n = 7; // Change value of n for varying pattern sizes
    int i, j;

    for(i=1;i<=n/2;i++)
    {
        print_spaces(n/2-i+1);
        print_star(i*2-1);
        printf("\n");
    }
    for(i=n/2-1;i>=1;i--)
    {
        print_spaces(n/2-i+1);
        print_star(i*2-1);
        printf("\n");
    }

    return 0;
}

void print_star(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("* ");
    }
}

void print_spaces(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("  ");
    }
}