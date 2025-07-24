//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main()
{
   int n, i, j, space;
   printf("Enter the value of n: ");
   scanf("%d",&n);
   
   for(i=n; i>=1; i--)
   {
      for(space=0; space<n-i; space++)
         printf("  ");
         
      for(j=i; j<=2*i-1; j++)
         printf("%d ",j);
        
      for(j=0; j<i-1; j++)
         printf("%d ",j+i);
        
      printf("\n");
   }
    
   for(i=2; i<=n; i++)
   {
      for(space=0; space<n-i; space++)
         printf("  ");
         
      for(j=i; j<=2*i-1; j++)
         printf("%d ",j);
        
      for(j=0; j<i-1; j++)
         printf("%d ",j+i);
        
      printf("\n");
   }
   return 0;
}