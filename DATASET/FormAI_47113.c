//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

int main()
{
    int num, i, a = 0, b = 1, c;
    
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    
    printf("\nFibonacci Series: \n");

    for (i = 1; i <= num; i++) 
    {
        if (i == 1) 
        {
            printf("%d, ", a);
            continue;
        }
        if (i == 2) 
        {
            printf("%d, ", b);
            continue;
        }
        c = a + b;
        a = b;
        b = c;
        printf("%d, ", c);
        
        if (i % 10 == 0) // add a new line every 10 numbers
            printf("\n");
    }
    
    return 0;
}