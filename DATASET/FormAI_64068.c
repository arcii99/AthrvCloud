//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main() {
   int a;
   printf("Think of a number between 1 and 100, I will guess it!\n");
   printf("Enter '1' if the guessed number is smaller than your number. \n");
   printf("Enter '2' if the guessed number is greater than your number. \n");
   printf("Enter '3' if the guessed number is correct. \n");
   int min = 1, max = 100;
   int mid = (min+max)/2;
   printf("Is your number %d?\n", mid);
   scanf("%d", &a);
   while(a!=3) {
      if(a==1) {
         max = mid-1;
      } else if(a==2) {
         min = mid+1;
      }
      mid = (min+max)/2;
      printf("Is your number %d?\n", mid);
      scanf("%d", &a);
   }
   printf("Yay! I guessed your number!\n");
   return 0;
}