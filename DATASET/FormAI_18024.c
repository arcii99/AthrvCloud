//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdbool.h>

// maximum number of terms to be displayed in the sequence
#define MAX_TERMS 50

// function to generate the Fibonacci sequence
void generateFibonacciSequence(int numberOfTerms)
{
    // declare the first two terms of the sequence
    int term1 = 0, term2 = 1;
    
    // print the first term
    printf("%d ", term1);
    
    // if only one term to print, return
    if(numberOfTerms == 1)
        return;
    
    // print the second term
    printf("%d ", term2);
    
    // if only two terms to print, return
    if(numberOfTerms == 2)
        return;
    
    // loop to generate the subsequent terms
    for(int i = 2; i < numberOfTerms; i++)
    {
        int currentTerm = term1 + term2;
        printf("%d ", currentTerm);
        term1 = term2;
        term2 = currentTerm;
    }
}

int main()
{
    int numberOfTerms;
  
    // get the number of terms from the user
    printf("Enter the number of terms to be displayed in the Fibonacci sequence: ");
    scanf("%d", &numberOfTerms);
  
    // validate the input
    while(numberOfTerms < 1 || numberOfTerms > MAX_TERMS)
    {
        printf("Please enter a number between 1 and %d: ", MAX_TERMS);
        scanf("%d", &numberOfTerms);
    }
  
    // generate and display the Fibonacci sequence
    printf("The Fibonacci sequence of %d terms is:\n", numberOfTerms);
    generateFibonacciSequence(numberOfTerms);
  
    return 0;
}