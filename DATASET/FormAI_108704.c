//FormAI DATASET v1.0 Category: Game ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

void main(){
   int a, b, c;
   char ch;
   
   printf("Enter the first number: ");
   scanf("%d", &a);
   
   printf("Enter the second number: ");
   scanf("%d", &b);
   
   printf("Choose an operation (+, -, *, /): ");
   scanf(" %c", &ch);
   
   switch(ch){
      case '+':
         c = a + b;
         break;
      case '-':
         c = a - b;
         break;
      case '*':
         c = a * b;
         break;
      case '/':
         c = a / b;
         break;
      default:
         printf("Invalid operation.");
         exit(0);
   }
   
   printf("The answer is: %d", c);
   
   return(0);
}