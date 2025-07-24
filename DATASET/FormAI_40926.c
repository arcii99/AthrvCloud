//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include<stdio.h>
 
int main()
{
    int n, i, j, flag;
    printf("Enter the range of prime numbers you want to generate: ");
    scanf("%d",&n);
 
    //2 is the smallest prime number
    printf("Prime Numbers:\n2\n");

    for(i=3;i<=n;i+=2)
    {
        flag=0;
        
        //checking if the number is prime or not
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        
        //printing if the number is prime
        if(flag==0)
            printf("%d\n",i);
    }

    return 0;
}