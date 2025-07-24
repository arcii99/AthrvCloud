//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

int main() {
   int p = 11;
   int q = 13;
   int n = p * q;
   int phi = (p-1) * (q-1);

   int e = 7;
   while (e < phi) {
      if (gcd(e, phi) == 1)
         break;
      else
         e++;
   }

   int d;
   int k = 2;
   d = (1 + (k*phi)) / e;

   char message[] = "Hello, World!";
   int i = 0;
   while (message[i]) {
      int c = message[i];
      int encrypted = 1;
      for (int j=0; j<e; j++) {
         encrypted *= c;
         encrypted %= n;
      }
      printf("%d ", encrypted);
      i++;
   }

   printf("\n");

   return 0;
}