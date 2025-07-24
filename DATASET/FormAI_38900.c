//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include<stdio.h>

void Fibonacci(int);
int main()
{
   int n;
   printf("Enter the limit to generate the fibonacci sequence: ");
   scanf("%d",&n);
   Fibonacci(n);
   return 0;
}

void Fibonacci(int n)
{
   int f1 = 0, f2 = 1, i, nextTerm;
   printf("%d %d ",f1,f2);
   for(i=3;i<=n;i++)
   {
       nextTerm = f1 + f2;
       f1 = f2;
       f2 = nextTerm;
       printf("%d ",nextTerm);
   }
}