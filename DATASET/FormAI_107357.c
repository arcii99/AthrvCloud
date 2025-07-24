//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
#include <stdio.h>

int main() {
   //Declare variables
   int n, sum = 0;
   char op;
   printf("Enter the number of elements you want to operate on: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter %d elements:\n", n);
  
   //Fill array
   for(int i = 0; i < n; i++){
       scanf("%d", &arr[i]);
   }
   
   printf("Enter the operation you want to perform (+ or -): ");
   scanf(" %c", &op);

   //Choose operation
   if(op == '+'){
       for(int i = 0; i < n; i++){
           sum += arr[i];
       }
       printf("The sum of the elements is: %d\n", sum);
   } 
   else if(op == '-'){
       for(int i = 0; i < n; i++){
           sum -= arr[i];
       }
       printf("The difference of the elements is: %d\n", sum);
   } else {
       printf("Invalid operator.\n");
   }

   return 0;
}