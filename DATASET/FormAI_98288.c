//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   int num, i;
   printf("Enter any number: ");
   scanf("%d", &num);

   for(i = 2; i <= num/2; i++) {

      if(num % i == 0) {
         printf("%d is not a prime number.", num);
         break;
      }
   }
   
   if(i > num/2) {
      printf("%d is a prime number.", num);
   }

   return 0;
}