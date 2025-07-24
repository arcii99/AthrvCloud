//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include<stdio.h>
#include<math.h>

// to find gcd of two numbers
int gcd(int a, int b) {
   if(b==0) {
      return a;
   }
   return gcd(b, a%b);
}

// to compute (a^b)%mod
int power(int a, int b, int mod) {
   int res=1;
   a=a%mod;
   while(b>0) {
      if(b&1 == 1) {
         res=(res*a)%mod;
      }
      b=b>>1;
      a=(a*a)%mod;
   }
   return res;
}

int main() {
   int p=3, q=7, n, phi, e=2, d, m=12, c, dec;

   // calculate n, phi, and e
   n=p*q;
   phi=(p-1)*(q-1);
   while(e<phi) {
      if(gcd(e, phi)==1) {
         break;
      }
      e++;
   }

   // calculate private key, d
   d=(1+(2*phi))/e;

   // Encryption
   c=power(m, e, n);
   printf("Encrypted message: %d\n", c);

   // Decryption
   dec=power(c, d, n);
   printf("Decrypted message: %d\n", dec);
   return 0;
}