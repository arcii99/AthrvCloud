//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include<stdio.h>
int main()
{
    int j=1,k=1,p=0,a=0,b=0,c=0,d=0;
    printf("Get ready for some fun and energy!\n");
    printf("We will generate a series of numbers that are a mix of Fibonacci and prime numbers\n");
    printf("Enter how many numbers should be printed: ");
    scanf("%d",&p);
    while(d<p)
    {
        int i=1;
        while(i<=j)
        {
            if(j%i==0)
                b++;
            if(b>2)
                break;
            i++;
        }
        if(b==2)
        {
            printf("%d ",j);
            d++;
        }
        else
        {
            a=k;
            k=j;
            j=a+k;
            printf("%d ",k);
            d++;
        }
        b=0;
    }
    printf("\nHope you had fun! See you soon :)");
    return 0;
}