//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

void printNumbers(int x)
{
    if(x>=0)
    {
        printf("%d ", x);
        printNumbers(x-1);
    }
}

int main()
{
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    printf("The numbers from %d to 0 are: ", n);
    printNumbers(n);

    return 0;
}