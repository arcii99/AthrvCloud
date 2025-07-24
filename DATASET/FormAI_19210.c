//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//declaration of variables
    int i, n, a = 0, b = 1, c = 0;

    //user input for number of terms to print
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);

    //checking for special cases
    if (n == 1)
    {
        printf("%d", a);
    }
    else if (n == 2)
    {
        printf("%d %d", a, b);
    }
    else
    {
        printf("%d %d ", a, b);

        //loop to generate fibonacci sequence
        for (i = 3; i <= n; i++)
        {
            c = a + b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }

    return 0;
}