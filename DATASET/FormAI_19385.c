//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include<stdio.h>

void main(){
   int num1, num2, result;
   printf("Enter two numbers: ");
   scanf("%d %d", &num1, &num2);

   if(num2 == 0){
      printf("Divide by zero error detected! Now self-destructing all servers... \n");
      printf("3, 2, 1... BOOM!!!");

      // Error code: Server explosion
      int *ptr = NULL;
      *ptr = 100;
   }
   else{
      result = num1/num2;
      printf("The result is: %d", result);
   }
}