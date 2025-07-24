//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include<stdio.h>

int main()
{
    int n,i;
    printf("Enter the number of terms you want to generate in Fibonacci sequence:\n");
    scanf("%d",&n);
    int F[n];
    F[0]=0;
    F[1]=1;
    printf("\nThe Fibbonaci Sequence for the given number of terms is:\n\n");
    printf("%d, %d",F[0],F[1]);
    for(i=2;i<n;i++)
    {
        F[i]=F[i-1]+F[i-2];
        printf(", %d",F[i]); 
    }
    return 0;
}