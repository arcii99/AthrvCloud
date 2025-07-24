//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>

int Fibonacci(int num) // function to calculate Fibonacci value
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return (Fibonacci(num-1) + Fibonacci(num-2)); // recursive call to Fibonacci function
}

int main()
{
    int num; // variable to hold number of terms in sequence
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &num);

    printf("Fibonacci Sequence: ");
    for(int i=0; i<num; i++)
        printf("%d ", Fibonacci(i)); // calling the Fibonacci function for each term

    return 0;
}