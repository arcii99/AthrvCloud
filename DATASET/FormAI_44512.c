//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

void print_futuristic_pattern(int n)
{
    int i, j, k;

    // Base case
    if(n <= 0)
        return;

    // Recursive case
    print_futuristic_pattern(n-1);

    // Print the pattern
    for(i = 0; i < n; i++)
    {
        for(j = n-i-1; j > 0; j--)
            printf(" ");

        for(k = 0; k <= i; k++)
            printf("* ");

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of lines in the pattern: ");
    scanf("%d", &n);

    print_futuristic_pattern(n);

    return 0;
}