//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
// A C program to find the sum of first n numbers
// in a unique Ada Lovelace style

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: Entered number is not a positive integer!\n");
        return 1;
    }

    for (int i=1; i<=n; i++) {
        sum += i;
    }

    printf("The sum of first %d numbers is %d\n", n, sum);

    // Ada Lovelace inspired message
    printf("The analytical engine has computed the result with great efficiency!\n");

    return 0;
}