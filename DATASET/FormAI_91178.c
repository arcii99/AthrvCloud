//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include<stdio.h>

int main(){
   int a = 10;
   int b = 5;

   printf("The sum of %d and %d is %d\n", a, b, a+b);
   printf("The difference between %d and %d is %d\n", a, b, a-b);
   printf("The product of %d and %d is %d\n", a, b, a*b);

   if(b != 0){
      printf("The quotient of %d and %d is %d\n", a, b, a/b);
      printf("The remainder when %d is divided by %d is %d\n", a, b, a%b);
   }
   else{
      printf("Division by zero is invalid!\n");
   }

   printf("The increment of %d is %d\n", a, ++a);
   printf("The decrement of %d is %d\n", b, --b);

   return 0;
}