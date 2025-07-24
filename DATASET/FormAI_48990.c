//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PRIME 9999
#define MIN_PRIME 1000

int is_prime(int n)
{
    int i;
    if(n<2)
        return 0;
    for(i=2;i<sqrt(n)+1;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int modExp(int a, int b, int n)
{
    if(b==0)
        return 1;
    if(b%2==0)
        return modExp((a*a)%n,b/2,n);
    return (a*modExp(a,b-1,n))%n;
}

int modInv(int a, int n)
{
    int t=0, nt=1, r=n, nr=a, q, tmp;
    while(nr!=0)
    {
        q=r/nr;
        tmp=nt; nt=t-q*nt; t=tmp;
        tmp=nr; nr=r-q*nr; r=tmp;
    }
    if(r>1)
        return -1;
    if(t<0)
        t+=n;
    return t;
}

int generate_prime()
{
    srand(time(NULL));
    int n;
    do {
        n=rand()%(MAX_PRIME-MIN_PRIME+1)+MIN_PRIME;
    } while(!is_prime(n));
    return n;
}

int main()
{
    printf("RSA Algorithm Implementation\n\n");

    int p=generate_prime();
    int q=generate_prime();
    int n=p*q;
    printf("Generated Primes: %d and %d\n",p,q);
    printf("Public Key n: %d\n",n);

    int phi=(p-1)*(q-1);
    int e;
    do{
        e=rand()%(phi-2)+2;
    } while(gcd(e,phi)!=1);
    printf("Public Key E: %d\n",e);

    int d=modInv(e,phi);
    printf("Private Key D: %d\n",d);

    printf("\nEnter a message: ");
    int m;
    scanf("%d",&m);
    int c=modExp(m,e,n);
    printf("Encrypted message: %d\n",c);

    int m2=modExp(c,d,n);
    printf("Decrypted message: %d\n",m2);

    return 0;
}