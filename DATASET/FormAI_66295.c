//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime(int n)
{
   int i, flag = 1;

   for(i=2; i<=n/2; ++i)
   {
      if(n%i == 0)
      {
         flag = 0;
         break;
      }
   }

   return flag;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int p, q, n, phi, e, d, plainText, cipherText, decryptedText;

    printf("Enter a prime number: ");
    scanf("%d", &p);

    while(!prime(p))
    {
        printf("%d is not prime. Enter a prime number: ", p);
        scanf("%d", &p);
    }

    printf("Enter another prime number: ");
    scanf("%d", &q);

    while(!prime(q))
    {
        printf("%d is not prime. Enter another prime number: ", q);
        scanf("%d", &q);
    }

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("Enter a number between 1 and %d which is co-prime to %d: ", phi, phi);
    scanf("%d", &e);

    while(gcd(e, phi) != 1 || e <= 1 || e >= phi)
    {
        printf("Invalid input. Enter a number between 1 and %d which is co-prime to %d: ", phi, phi);
        scanf("%d", &e);
    }

    //calculating d
    int k = 1;
    while(1) {
        if((k * phi + 1) % e == 0) {
            d = (k * phi + 1) / e;
            break;
        }
        k++;
    }

    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);

    printf("Enter a number to be encrypted: ");
    scanf("%d", &plainText);

    cipherText = ((int)pow(plainText, e)) % n;
    printf("Encrypted number: %d\n", cipherText);

    decryptedText = ((int)pow(cipherText, d)) % n;
    printf("Decrypted number: %d\n", decryptedText);

    return 0;
}