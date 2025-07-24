//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int generate_key(int* pub_key, int* priv_key, int prime1, int prime2){
    int n = prime1 * prime2;
    int phi = (prime1 - 1) * (prime2 - 1);
    int e, d;
    srand(time(0));
    do{
        e = rand()%phi;
    }while(gcd(e, phi) != 1);

    int k = 1;
    while(1){
        k = k + phi;
        if(k%e == 0){
            d = k/e;
            break;
        }
    }

    *pub_key = e;
    *priv_key = d;
    return n;
}

int encrypt(int m, int e, int n){
    int i, c = 1;
    for(i = 0; i < e; i++){
        c = (c * m) % n;
    }
    return c;
}

int decrypt(int c, int d, int n){
    int i, m = 1;
    for(i = 0; i < d; i++){
        m = (m * c) % n;
    }
    return m;
}

int main(){
    int prime1 = 61;
    int prime2 = 53;
    int pub_key, priv_key;
    int n = generate_key(&pub_key, &priv_key, prime1, prime2);

    int message = 77;
    int cipher = encrypt(message, pub_key, n);
    printf("Message: %d\nEncrypted: %d\n", message, cipher);

    int decrypted = decrypt(cipher, priv_key, n);
    printf("Decrypted: %d\n", decrypted);

    return 0;
}