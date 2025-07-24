//FormAI DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n > 0)
    {
        printf("%d is a positive number.\n", n);
    }
    else if(n < 0)
    {
        printf("%d is a negative number.\n", n);
    }
    else
    {
        printf("You have entered zero.\n");
    }

    return 0;
}