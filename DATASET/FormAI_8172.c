//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50
#define MAX_PQ 200

int MAX(int a, int b){
    return a>b?a:b;
}

int MIN(int a, int b){
    return a<b?a:b;
}

int EXTENDED_EUCLID(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0; *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = EXTENDED_EUCLID(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int IS_PRIME(int n){
    if(n<=1) return 0;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int MODULUS_INV(int a, int m){
    int x, y;
    int gcd = EXTENDED_EUCLID(a, m, &x, &y);
    if(gcd != 1) return -1; // not inversible
    return (x%m + m) % m;
}

int POWER_MOD(int a, int b, int m){ // m must be prime
    if(b == 0) return 1;
    if(b == 1) return a%m;
    int t = POWER_MOD(a, b/2, m);
    if(b%2 == 0) return (long long)t*t%m;
    return ((long long)t*t%m)*a%m;
}

int RAND_PRIME(int lower_bound, int upper_bound){
    int n = upper_bound-lower_bound+1;
    int prime[SIZE], siz=0;
    for(int i=lower_bound; i<=upper_bound; i++){
        if(IS_PRIME(i)) prime[siz++] = i;
    }
    if(siz == 0) return -1;
    srand(time(NULL));
    int x = prime[rand()%siz];
    for(int t=0; t<200; t++){
        int i = rand()%siz;
        int j = rand()%siz;
        int p = prime[i], q = prime[j];
        if(x==p || x==q) continue;
        int phi = (p-1)*(q-1);
        if(EXTENDED_EUCLID(x, phi, NULL, NULL) != 1) continue;
        int d = MODULUS_INV(x, phi);
        if(d == -1) continue;
        if(POWER_MOD(x, d, p) != 1 || POWER_MOD(x, d, q) != 1) continue;
        return x;
    }
    return -1;
}

int main(){
    int p = RAND_PRIME(50, 100);
    int q = RAND_PRIME(300, 400);
    if(p == -1 || q == -1){
        printf("Invalid input\n");
        return 0;
    }
    int N = p * q;
    int phi = (p-1)*(q-1);
    int e;
    for(int i=2; i<phi; i++){
        if(EXTENDED_EUCLID(i, phi, NULL, NULL) == 1){
            e = i;
            break;
        }
    }
    int d = MODULUS_INV(e, phi);
    printf("Public Key : { %d, %d }\n", e, N);
    printf("Private Key : { %d, %d }\n", d, N);
    return 0;
}