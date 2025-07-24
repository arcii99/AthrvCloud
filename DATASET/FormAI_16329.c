//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>

int main() {
   char input[100];
   int i, j, len;
   double num1=0, num2=0, result=0;

   printf("Enter an expression (e.g: 2 + 3.4):\n");
   fgets(input, 100, stdin); // read input from user

   len = strlen(input); // get length of input

   for(i=0; i<len; i++){ // loop through chars in input
      if(input[i] >= '0' && input[i] <= '9'){ // check for numbers
         double num = 0.0;
         int decimal = 0; // keep track of decimal places 

         while(input[i] >= '0' && input[i] <= '9' || input[i] == '.'){ // grab the entire number
            if(input[i] == '.') decimal++;
            if(decimal <= 1){
               if(decimal = 1){ // decimal places
                  num = num + (input[i] - '0') * pow(10, -decimal);
                  i++;
               }
               else {
                  num = num * 10 + (input[i] - '0');
                  i++;
               }
            }
            else { 
               printf("Invalid number!\n"); // too many decimal points
               return 0;
            }
         }
         if(!num1) num1 = num; // assign num to num1 if num1 is empty
         else num2 = num; // assign num to num2 if num1 is not empty
      }

      if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){ // check for operators
         char operator = input[i];
         i++;
         while(input[i] == ' ') i++; // skip spaces
         if(input[i] >= '0' && input[i] <= '9'){ // grab second number
            double num = 0.0;
            int decimal = 0; // keep track of decimal places

            while(input[i] >= '0' && input[i] <= '9' || input[i] == '.'){
               if(input[i] == '.') decimal++;
               if(decimal <= 1){
                  if(decimal = 1){ // decimal places
                     num = num + (input[i] - '0') * pow(10, -decimal);
                     i++;
                  }
                  else {
                     num = num * 10 + (input[i] - '0');
                     i++;
                  }
               }
               else {
                  printf("Invalid number!\n"); // too many decimal points
                  return 0;
               }
            }
            if(operator == '+') result = num1 + num2; // perform calculations based on operator
            if(operator == '-') result = num1 - num2;
            if(operator == '*') result = num1 * num2;
            if(operator == '/') {
               if(num2 == 0){ // check for division by zero
                  printf("Cannot divide by zero!\n");
                  return 0;
               }
               result = num1 / num2;
            }
            num1 = result; // assign result to num1 for future calculations
            num2 = 0;
         } else{
            printf("Invalid expression!\n"); // cannot follow operator with non-number
            return 0;
         }
      }

      if(input[i] == ' ') i++; // skip spaces
   }

   if(num1 || num2 || result) printf("The result is %.2lf\n", result); // final result
   else printf("Invalid expression!\n"); // no valid expression found

   return 0;
}