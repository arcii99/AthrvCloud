//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

int main() {
   int num1, num2, sum, sub, product;
   float quotient;
   
   printf("Enter the first number: ");
   scanf("%d", &num1); //Input first number
   
   printf("Enter the second number: ");
   scanf("%d", &num2); //Input second number
   
   sum = num1+num2; //Calculating sum
   
   if(num1>num2){
      sub = num1-num2; //Calculating difference
   } else{
      sub = num2-num1;
   }
   
   product = num1*num2; //Calculating product
   
   if(num2 != 0){
      quotient = (float)num1/(float)num2; //Calculating quotient with float typecasting
   }else{
      printf("Cannot divide by zero");
   }
   
   //Printing the results
   printf("The sum is %d", sum);
   printf("The difference is %d", sub);
   printf("The product is %d", product);
   printf("The quotient is %.2f", quotient);
   
   return 0;
}