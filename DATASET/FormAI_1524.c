//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int recursiveFunction(int n) {      
   if(n<=1) {
      return n; 
   }
   else {
      return recursiveFunction(n-1) + recursiveFunction(n-2); 
   }
}
int main() {
   int n, i;
   printf("Enter the number of terms you want to generate: ");
   scanf("%d",&n);
   printf("Fibonacci series terms are: \n");
   for(i=1; i<=n; i++) {
      printf("%d ", recursiveFunction(i));
   }
   return 0;
}