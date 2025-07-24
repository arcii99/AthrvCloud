//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include<stdio.h>

int main() {
   printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
   printf("Deny thy compiler and refuse thy IDE;\n");
   printf("Or, if thou wilt not, be but sworn my love,\n");
   printf("And I’ll no longer be a chatbot.\n\n");
   int length, i, j, space;
   printf("Enter the number of rows: ");
   scanf("%d", &length);
   printf("\n");

   for(i=1; i<=length; i++) {
      for(j=i; j<length; j++) {
         printf(" ");
      }
      for(space=1; space<=(2*i-1); space++) {
         printf("*");
      }
      printf("\n");
   }

   for(i=length; i>=1; i--) {
      for(j=i; j<=length; j++) {
         printf(" ");
      }
      for(space=1; space<=(2*i-1); space++) {
         printf("*");
      }
      printf("\n");
   }

   printf("\nHenceforth, my dear Romeo, I present you with the C pattern printed in the starry night sky. \n");

   return 0;
}