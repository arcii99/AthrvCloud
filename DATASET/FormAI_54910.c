//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int gcd(long long int a, long long int b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

long long int power(long long int a, long long int b, long long int m){
    long long int res = 1;
    a = a%m;
    while(b>0){
        if(b&1){
            res = (res*a)%m;
        }
        b /= 2;
        a = (a*a)%m;
    }
    return res;
}

int isPrime(long long int p){
    if(p<=1 || (p%2==0 && p!=2)){
        return 0;
    }
    for(long long int i=3; i*i<=p; i+=2){
        if(p%i==0){
            return 0;
        }
    }
    return 1;
}

long long int getPrivateKey(long long int e, long long int phi){
    long long int x, y, gcd_res;
    for(long long int i=2; i<phi; i++){
        gcd_res = gcd(i, phi);
        if(gcd_res==1){
            x = phi+i;
            y = power(i, x, phi);
            while(y!=1){
                x += phi;
                y = power(i, x, phi);
            }
            if(x%e==0){
                return x/e;
            }
        }
    }
    return -1;
}

void generateKeys(long long int p, long long int q, long long int* pubkey, long long int* privkey){
    long long int n = p*q;
    long long int phi = (p-1)*(q-1);
    long long int e = 2;
    while(e<phi){
        if(gcd(e, phi)==1){
            break;
        }
        e++;
    }
    *pubkey = e;
    *privkey = getPrivateKey(e, phi);
}

long long int encrypt(long long int m, long long int e, long long int n){
    return power(m, e, n);
}

long long int decrypt(long long int c, long long int d, long long int n){
    return power(c, d, n);
}

int main(){
    long long int p = 53;
    long long int q = 59;
    if(!isPrime(p) || !isPrime(q)){
        printf("Error: p and q must be prime numbers.\n");
        return 0;
    }
    long long int pubkey, privkey;
    generateKeys(p, q, &pubkey, &privkey);
    printf("Public key: (%lld, %lld)\n", pubkey, p*q);
    printf("Private key: (%lld, %lld)\n", privkey, p*q);
    long long int m = 12345;
    long long int c = encrypt(m, pubkey, p*q);
    printf("Plaintext message: %lld\n", m);
    printf("Encrypted message: %lld\n", c);
    long long int d = decrypt(c, privkey, p*q);
    printf("Decrypted message: %lld\n", d);
    return 0;
}