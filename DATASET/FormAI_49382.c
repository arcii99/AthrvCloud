//FormAI DATASET v1.0 Category: Educational ; Style: irregular
#include <stdio.h>

void print_odd_numbers(int n);

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Printing odd numbers from 1 to %d\n", n);
    print_odd_numbers(n);

    return 0;
}

void print_odd_numbers(int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(i % 2 != 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");
}