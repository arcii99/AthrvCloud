//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int h) {
   int temp;
   while (1) {
      temp = a%h;
      if (temp == 0)
         return h;
      a = h;
      h = temp;
   }
}

int main() {

   // Step 1: Choose two prime numbers
   int p = 3;
   int q = 7;

   // Step 2: Compute n
   int n = p*q;

   // Step 3: Compute totient
   int totient = (p-1)*(q-1);

   // Step 4: Choose an integer e such that 1 < e < totient and gcd(e, totient) = 1
   int e = 2;
   while (e < totient) {
      if (gcd(e, totient)==1)
         break;
      else
         e++;
   }

   // Step 5: Compute d such that d*e = 1 mod totient
   int i = 1;
   int d;
   while (1) {
      if (((totient*i)+1)%e == 0) {
         d = ((totient*i)+1)/e;
         break;
      }
      i++;
   }

   // Step 6: Print public key (n,e) and private key (n,d)
   printf("Public Key: (%d,%d)\nPrivate Key: (%d,%d)\n",n,e,n,d);

   return 0;
}