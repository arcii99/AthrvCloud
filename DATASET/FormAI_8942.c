//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include<stdio.h>

int main(){
   int num1,num2,result;

   printf("Enter two numbers\n");
   if(scanf("%d%d", &num1, &num2) != 2){
      printf("Error: Invalid input");
      return 1;
   }
   if(num2 == 0){
      printf("Error: Divide by zero\n");
      return 2;
   }
   result = num1/num2;
   printf("%d / %d = %d\n",num1,num2,result);

   return 0;
}