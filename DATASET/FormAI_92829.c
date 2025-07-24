//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

// function prototype
void printNaturalNumbers(int);

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Natural numbers from 1 to %d: ", n);
    printNaturalNumbers(n);

    return 0;
}

void printNaturalNumbers(int n)
{
    if (n <= 0)
        return;

    printNaturalNumbers(n - 1);
    printf("%d ", n);
}