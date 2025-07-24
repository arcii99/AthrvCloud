//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
#include <stdio.h>

// function prototype
void fibonacci_visualizer(int n);

int main()
{
    int n;
    // get input from user
    printf("Enter the number of terms in the Fibonacci sequence to visualize: ");
    scanf("%d", &n);
    // call the function to visualize the sequence
    fibonacci_visualizer(n);
    return 0;
}

void fibonacci_visualizer(int n)
{
    int a = 0, b = 1, c;
    // print the first two terms in the sequence
    printf("%d %d ", a, b);
    // loop through the remaining terms in the sequence
    for(int i = 3; i <= n+2; i++)
    {
        c = a + b;
        a = b;
        b = c;
        // print each term in the sequence with appropriate visual representation
        if(c % 5 == 0 && c % 3 == 0) // check for divisibility by 3 and 5
        {
            printf("*!\t");
        }
        else if(c % 3 == 0) // check for divisibility by 3
        {
            printf("*\t");
        }
        else if(c % 5 == 0) // check for divisibility by 5
        {
            printf("!\t");
        }
        else // print the term as is
        {
            printf("%d\t", c);
        }
    }
}