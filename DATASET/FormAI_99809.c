//FormAI DATASET v1.0 Category: Funny ; Style: sophisticated
#include <stdio.h>

int main() {
   int number, i;
   printf("Enter a positive integer: ");
   scanf("%d",&number);
   if(number >= 1) {
      printf("The first %d natural numbers are: ",number);
      for(i=1; i <= number; i++) {
         printf("%d ",i);
      }
   }
   else {
      printf("Invalid input! Please enter a positive integer.");
   }
   return 0;
}