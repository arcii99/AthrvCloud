//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int a = 0, b = 1;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    printf("The Fibonacci Sequence is:\n");
    for(i=1; i<=n; i++)
    {
        printf("%d, ", a);
        int sum = a + b;
        a = b;
        b = sum;
        if(i % 10 == 0) // Add some surrealist touch with a delay and a message
        {
            printf("\n\nThe Fibonacci sequence is getting surreal...\n\n");
            sleep(3); // Add delay of 3 seconds
        }
    }
    return 0;
}