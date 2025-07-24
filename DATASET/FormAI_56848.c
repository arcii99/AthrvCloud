//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>

int main() {
   int i, j, n, flag;

   printf("Enter a number to check for prime numbers: ");
   scanf("%d", &n);

   printf("The prime numbers up to %d are: ", n);

   for(i=2; i<=n; i++) {
      flag = 0;
      
      for(j=2; j<=i/2; j++) {
         
         if(i%j == 0) {
            flag = 1;
            break;
         }
      }
      
      if(flag == 0 && i != 1)
         printf("%d ",i);
   }
   
   return 0;
}