//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
/* A program to calculate Fibonacci series*/
#include<stdio.h>

int main()
{
    int n, firstTerm = 0, secondTerm = 1, nextTerm, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series: ");
    
    for(i=1; i<=n; i++)
    {
        if(i == 1)
        {
            printf("%d, ", firstTerm);
            continue;
        }
        if(i == 2)
        {
            printf("%d, ", secondTerm);
            continue;
        }
        
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        
        printf("%d, ", nextTerm);
        
    }
    
    return 0;
}