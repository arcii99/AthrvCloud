//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("The prime numbers between 2 and %d are: \n",n);
    for(int i=2;i<=n;i++)
    {
        if(is_prime(i))
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}