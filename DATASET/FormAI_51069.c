//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>

int isPrime(int n);

int main() {
   int n, i;
   printf("Enter an integer: ");
   scanf("%d",&n);
   printf("Prime numbers upto %d: ",n);
   for(i=2; i<=n; i++) {
      if(isPrime(i))
         printf("%d ",i);
   }
   return 0;
}

int isPrime(int n) {
   int i;
   for(i=2; i<=n/2; i++) {
      if (n%i==0)
         return 0;
   }
   return 1;
}