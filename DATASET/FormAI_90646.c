//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include<stdio.h>
#include<math.h>

int main()
{
    int p, q, n, eta, e, d, message;
    printf("Enter two prime numbers p and q: ");
    scanf("%d %d",&p,&q);
    
    n = p*q;
    eta = (p-1)*(q-1);

    //finding public key e
    printf("Finding public key e...\n");
    for (int i=2; i<eta; i++)
    {
        if (eta%i != 0 && gcd(i, eta)==1)
        {
            e = i;
            break;
        }
    }

    //finding private key d
    printf("Finding private key d...\n");
    d = mod_inverse(e, eta);

    printf("Public key (n, e) = (%d, %d)\n", n, e);
    printf("Private key (n, d) = (%d, %d)\n", n, d);

    //encryption
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);
    int cipher = pow(message, e);
    cipher = cipher % n;
    printf("Encrypted message: %d\n", cipher);

    //decryption
    printf("Decrypting the message...\n");
    int decrypted = pow(cipher, d);
    decrypted = decrypted % n;
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}

//function to find gcd of two numbers
int gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

//function to find modular inverse of a number
int mod_inverse(int a, int m)
{
    for (int x=1; x<m; x++)
        if ((a%m * x%m) % m == 1)
            return x;
}