//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)
{
    if(num == 1)
        return false;
        
    for(int i = 2; i <= (num/2); i++)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int main()
{
    int n;
    printf("Enter number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("\n");
    
    int count = 0, num = 2;
    while(count < n)
    {
        if(is_prime(num))
        {
            printf("%d ", num);
            count++;
        }
        
        num++;
    }
    
    return 0;
}