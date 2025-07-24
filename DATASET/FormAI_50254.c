//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include<stdio.h>
int main()
{
   int n,i,j,k;
   printf("How funny you want the pattern to be?(1-10): ");
   scanf("%d",&n);
   if(n>10)
   {
      printf("Are you really asking for %d? That's hilarious!\n",n);
   }
   else
   {
      printf("Okay, let me print a pattern for you: \n");
   }
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n-i;j++)
      {
         printf(" ");
      }
      for(k=1;k<=i;k++)
      {
         printf("* ");
      }
      printf("\n");
   }
   printf("Ta-da! How funny was it? If it wasn't funny, you can always change the value of 'n'.\n");
   return 0;
}