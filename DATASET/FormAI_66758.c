//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

int findFactorial(int num) {  
   if(num == 1) {  
       return 1;  
   } else {  
       return num * findFactorial(num - 1);  
   }  
}  

int main() {  
   int num, factorial;  

   printf("Welcome to the Factorial Calculator!\n"); 
   printf("Please enter a positive integer: ");  
   scanf("%d", &num);  

   factorial = findFactorial(num);  
   printf("Factorial of %d is %d.\n", num, factorial);  

   printf("Thanks for using the Factorial Calculator!\n"); 

   return 0;  
}