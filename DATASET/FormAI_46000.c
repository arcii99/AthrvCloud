//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>

int main()
{
    int count, n, i, flag;

    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &count);

    printf("\nFirst %d prime numbers are: \n", count);

    for(n=2; count>0; n++)
    {
        flag=0;
        for(i=2; i<=n/2; i++)
        {
            if(n%i==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d ",n);
            count--;
        }
    }
    return 0;
}