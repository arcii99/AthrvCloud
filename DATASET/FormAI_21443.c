//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>

int main() {

   int num;
   printf("Hey there! Welcome to my happy C program! Let's spread some joy!\n");
   printf("Please enter a number between 1 and 10: ");
   scanf("%d", &num);

   if (num >= 1 && num <= 10) {
      for (int i=0; i<num; i++) {
         for (int j=0; j<num-i; j++) {
            printf(" ");
         }
         for (int j=0; j<=i; j++) {
            printf("%d ", i+1);
         }
         printf("\n");
      }
   }
   else {
      printf("Oh no! That's not between 1 and 10! Let's make the program stop to prevent errors! Goodbye! :)\n");
      return 0;
   }

   printf("Wow! That was so much fun! Thanks for sharing your number with me! Let's do it again sometime! Bye for now! :)\n");

   return 0;
}