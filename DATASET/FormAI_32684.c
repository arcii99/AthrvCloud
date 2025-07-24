//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include<stdio.h>

int main(){
   int num;
   int *ptr = NULL;

   printf("Enter a number: ");
   scanf("%d", &num);

   if(num > 10){
      printf("The entered number is greater than 10.\n");
   }
   else if(num < 0){
      printf("The entered number is less than zero.\n");
   }
   else{
      ptr = &num;
   }

   if(ptr == NULL){
      printf("Error detected. The pointer is NULL.\n");
      printf("Terminating program...\n");
      return 0;
   }

   *ptr = *ptr * 10;

   printf("Result: %d\n", *ptr);

   return 0;
}