//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>

// function to print the Fibonacci sequence up to n terms
void printFibonacciSequence(int n)
{
    int first = 0, second = 1, next, i;
    
    printf("Fibonacci sequence up to %d terms:\n", n);

    for (i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

// function to generate the Fibonacci sequence up to n terms and visualize it
void generateFibonacciSequenceVisualizer(int n)
{
    int first = 0, second = 1, next, i, j;
    int max_num_digits = 1, num_digits, num_spaces;
    
    // calculate the maximum number of digits for the largest number in the sequence
    for (i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        // calculate the number of digits for the current number
        num_digits = 1;
        while (next / 10 != 0)
        {
            num_digits++;
            next /= 10;
        }
        if (num_digits > max_num_digits)
        {
            max_num_digits = num_digits;
        }
    }
    
    // print the sequence and visualize it
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        // calculate the number of spaces needed to align the current number
        num_digits = 1;
        while (next / 10 != 0)
        {
            num_digits++;
            next /= 10;
        }
        num_spaces = max_num_digits - num_digits;
        // print the current number and fill in the remaining spaces with dots
        printf("%d", next);
        for (j = 0; j < num_spaces; j++)
        {
            printf(".");
        }
        printf(" ");
        // visualize the current number using asterisks
        for (j = 0; j < next; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n = 10;
    
    // print the Fibonacci sequence up to n terms
    printFibonacciSequence(n);
    
    printf("\n\n");
    
    // generate the Fibonacci sequence up to n terms and visualize it
    generateFibonacciSequenceVisualizer(n);
    
    return 0;
}