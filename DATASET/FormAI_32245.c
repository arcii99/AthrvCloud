//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int gcd(int a,int h)
{
    int temp;
    while (1)
    {
        temp=a%h;
        if(temp==0)
        {
          return h;
        }
        a=h;
        h=temp;
    }
}

int isPrime(int num)
{
    int i;
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
         return 0;
        }
    }
    return 1;
}

int generateRandomPrime(int n)
{
    int prime[n],count=0,i;
    for (i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
          prime[count]=i;
          count++;
        }
    }
    int randomIdx = rand() % count;
    return prime[randomIdx];
}

int generatePublicKey(int p, int q)
{
    int n=p*q;
    int phi=(p-1)*(q-1);
    int e=2;
    while(e<phi)
    {
        if(gcd(e,phi)==1)
        {
          break;
        }
        else
        {
          e++;
        }
    }
    return e;
}

int generatePrivateKey(int p, int q, int e)
{
    int n=p*q;
    int phi=(p-1)*(q-1);
    int k=2;
    int d = (1 + (k*phi))/e;
    while(d*e % phi != 1 || d==e)
    {
        k++;
        d = (1 + (k*phi))/e;
    }
    return d;
}

int main()
{
    int p = generateRandomPrime(50);
    int q = generateRandomPrime(60);
    printf("Prime1: %d and prime2: %d\n", p, q);
    int e = generatePublicKey(p,q);
    int d = generatePrivateKey(p, q, e);
    printf("Public Key: (%d,%d)\nPrivate Key: (%d,%d)\n", e,p*q,d,p*q);
    return 0;
}