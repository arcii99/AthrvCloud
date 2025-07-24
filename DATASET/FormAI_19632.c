//FormAI DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

int fib(int n){
   if(n <= 1){
      return n;
   }else{
      return fib(n-1) + fib(n-2);
   }
}

int main(){
   int n;
   printf("How many Fibonacci numbers should I generate?\n");
   scanf("%d", &n);
   
   printf("Fibonacci Sequence: ");
   for(int i=0; i<n; i++){
      printf("%d ", fib(i));
   }
   printf("\n");
   
   printf("Do you want to know the sum of the first %d Fibonacci numbers? (y/n)\n", n);
   char ans;
   scanf(" %c", &ans);
   if(ans == 'y'){
      int sum = 0;
      for(int i=0; i<n; i++){
         sum += fib(i);
      }
      printf("Sum of the first %d Fibonacci numbers: %d\n", n, sum);
   }else{
      printf("Suit yourself!\n");
   }
   
   printf("Now, do you want to generate the Fibonacci sequence in reverse order? (y/n)\n");
   scanf(" %c", &ans);
   if(ans == 'y'){
      printf("Fibonacci Sequence in Reverse: ");
      for(int i=n-1; i>=0; i--){
         printf("%d ", fib(i));
      }
      printf("\n");
   }else{
      printf("Okay then, goodbye!\n");
   }
   return 0;
}