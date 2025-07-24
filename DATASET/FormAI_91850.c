//FormAI DATASET v1.0 Category: Scientific ; Style: innovative
#include <stdio.h>

int main()
{
    int num, i, j, flag;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Prime numbers between 1-%d are: \n", num);
    
    // Loop from 2 to num, checking if each number is prime
    for(i=2; i<=num; i++)
    {
        flag = 1;
        
        // Loop from 2 to i-1, checking if i is divisible by any of those numbers
        for(j=2; j<=i/2; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        
        // If i is prime, print it out
        if(flag == 1)
        {
            printf("%d ", i);
        }
    }
    
    return 0;
}