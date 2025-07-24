//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main()
{
   int n;
   printf("Enter the number of rows: ");
   scanf("%d",&n);

   // Upper half
   for(int i=1; i<=n/2+1; i++)
   {
       for(int j=1; j<=n-i+1; j++)
           printf("  ");

       printf("* ");
       for(int j=1; j<=(i-1)*2-1; j++)
           printf("  ");
            
       if(i!=1)
           printf("* ");
            
       printf("\n");
   }
    
   // Lower half
   for(int i=n/2; i>=1; i--)
   {
       for(int j=1; j<=n-i+1; j++)
           printf("  ");

       printf("* ");
       for(int j=1; j<=(i-1)*2-1; j++)
           printf("  ");

       if(i!=1)
         printf("* ");
            
       printf("\n");
   }

   return 0;
}