//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>

#define N 5 // Define the order of the filter 

int main()
{
    int x[N]; // Define the input sequence
    int y[N] = {0}; // Define the output sequence initialized with zeros
    int a = 2; // Define the filter coefficient
    
    // Get input sequence
    
    printf("Enter input sequence: ");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
    }
    
    // Generate output sequence using the difference equation
    
    for(int n = 0; n < N; n++)
    {
        y[n] = x[n] + a*y[n-1];
    }
    
    // Print output sequence
    
    printf("Output sequence: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", y[i]);
    }
    
    return 0;
}