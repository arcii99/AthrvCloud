//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// This is a simple implementation of the RSA Algorithm

long long int gcd(long long int a,long long int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

long long int powmod(long long int x, long long int y, long long int p){
    long long int res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int isprime(long long int n, long long int k){
    if(n<=1 || n==4) return 0;
    if(n<=3) return 1;
    while(k>0){
        long long int a = 2 + rand()%(n-4);
        if(gcd(n,a)!=1) return 0;
        if(powmod(a,n-1,n)!=1) return 0;
        k--;
    }
    return 1;
}

long long int generate_prime(long long int start, long long int end){
    long long int diff = end - start + 1;
    while(1){
        long long int n = (rand()%diff)+start;
        if(isprime(n,5)) return n;
    }
}

long long int lcm(long long int a, long long int b){
    return (a*b)/gcd(a,b);
}

int main(){
    srand(time(NULL));
    
    long long int p = generate_prime(1000,10000); // Selecting primes p and q.
    long long int q = generate_prime(1000,10000);
    
    printf("Selected primes are: p=%lld, q=%lld\n",p,q);
    
    long long int n = p*q;
    long long int phi = lcm(p-1,q-1); // Computing Euler's totient.
    
    long long int e;
    for(e=2;e<phi;e++){ // Selecting public exponent e.
        if(gcd(e,phi)==1) break;
    }
    
    long long int d;
    for(d=1; d<phi; d++){ // Selecting secret exponent d.
        if((d*e)%phi==1) break;
    }
    
    printf("Public key is (e=%lld, n=%lld)\n",e,n);
    printf("Private key is (d=%lld, n=%lld)\n",d,n);
    
    // Encryption
    long long int msg;
    printf("Enter a message (integer): ");
    scanf("%lld",&msg);
    long long int c = powmod(msg,e,n); // Computing cipher using public key.
    printf("Cipher text is: %lld\n",c);
    
    // Decryption
    long long int m = powmod(c,d,n); // Computing original message using secret key.
    printf("Original message is: %lld\n",m);
    
    return 0;
}