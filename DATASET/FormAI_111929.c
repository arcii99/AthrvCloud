//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define bool int
#define true 1
#define false 0

bool isPrime(int n)
{
    if(n<=1)
        return false;
    else if(n<=3)
        return true;
    else if(n%2==0 || n%3==0)
        return false;
    int i=sqrt(n)+1,j;
    for(j=5;j<i;j+=6)
        if(n%j==0 || n%(j+2)==0)
            return false;
    return true;
}

int main()
{
    int n,i,count=0;
    printf("Enter the number of prime numbers required\n");
    scanf("%d",&n);
    printf("The first %d prime numbers are:\n",n);
    for(i=2;;i++)
    {
        if(isPrime(i))
        {
            printf("%d ",i);
            count++;
        }
        if(count==n)
            break;
    }
    return 0;
}