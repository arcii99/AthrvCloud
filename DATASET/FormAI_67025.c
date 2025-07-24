//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    printf("Oh my goodness! I can't believe we're implementing a Public-Key Algorithm in C! This is so exciting!\n\n");

    srand(time(NULL));

    int p, q, n, phi, e, d, msg, crypted_msg, decrypted_msg;

    printf("Let me tell you a secret...I am randomly generating two prime numbers...\n");
    p = getPrimeNumber();
    q = getPrimeNumber();
    printf("Prime number 1 = %d, Prime number 2 = %d\n", p, q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    printf("\nCalculating the values for Public-Key...\n");
    e = getRandomNumber(phi);
    while (gcd(e, phi) != 1)
    {
        e = getRandomNumber(phi);
    }
    printf("Public-Key (e, n) = (%d, %d)\n", e, n);

    printf("\nCalculating the values for Private-Key...\n");
    d = modInverse(e, phi);
    printf("Private-Key (d, n) = (%d, %d)\n", d, n);

    printf("\nTime to encrypt a message!\n");
    printf("Enter your message (an integer): ");
    scanf("%d", &msg);

    crypted_msg = encrypt(msg, e, n);
    printf("Encrypted message: %d\n", crypted_msg);

    printf("\nLet me decrypt this message for you!\n");
    decrypted_msg = decrypt(crypted_msg, d, n);
    printf("Decrypted message: %d\n", decrypted_msg);

    printf("\nThis was so much fun! I can't believe we just implemented a Public-Key Algorithm in C. Thank you for experiencing this with me!\n");

    return 0;
}

int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
       return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
        t = m;
 
        // m is remainder now, process
        // same as Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

int encrypt(int msg, int e, int n)
{
    return power(msg, e, n);
}

int decrypt(int crypted_msg, int d, int n)
{
    return power(crypted_msg, d, n);
}

int getPrimeNumber() 
{
    int num, i, flag;

    do {
        num = rand() % (1000 - 3 + 1) + 3; // Random integer between 3 and 1000
        flag = 1;
        for (i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                flag = 0;
                break;
            }
        }
    } while (!flag);

    return num;
}

int getRandomNumber(int max) 
{
    return rand() % max;
}