//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    int temp = 0;
    while (1) {
        temp = a % b;
        if (temp == 0) {
            return b;
        }
        a = b;
        b = temp;
    }
}

int main()
{
   int p = 13;
   int q = 23;
   int n = p*q;
   int e = 7;
   int phi = (p-1)*(q-1);
   while (e < phi)
   {
       if (gcd(e, phi)==1)
       {
           break;
       }
       else
       {
           e++;
       }
   }
   int k = 2;
   int d = (1 + (k*phi))/e;
   int message = 9;
   printf("Public Key: {%d, %d}\n", e, n);
   printf("Private Key: {%d, %d}\n", d, n);
   int c = pow(message, e);
   c = fmod(c, n);
   printf("Encrypted Message: %d\n", c);
   int decrypted = pow(c, d);
   decrypted = fmod(decrypted, n);
   printf("Decrypted Message: %d\n", decrypted);
   return 0;
}