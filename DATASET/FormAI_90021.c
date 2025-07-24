//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n, i, a=0, b=1, c;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("\n Here is your Fibonacci Sequence Visualizer:\n");
    for(i=0;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        if(a>b)
        {
            printf("*");
            continue;
        }
        else
        {
            while(a<b)
            {
                printf("%d ",a);
                a+=c;
                if(a>b)
                {
                    printf("*");
                    break;
                }
            }
        }
        printf("\n");
    }
}