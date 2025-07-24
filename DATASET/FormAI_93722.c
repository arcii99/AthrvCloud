//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b){
    int temp;
    while (1){
        temp = a%b;
        if(temp==0) return b;
        a = b;
        b = temp;
    }
}

int isprime(int a){
    int i;
    for(i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}

int main(){
    int p, q, n, z, d, e, message;   //declare variables
    
    //generate prime numbers
    do{
        printf("Enter a prime number p: ");
        scanf("%d",&p);
    }while(!isprime(p));
    
    do{
        printf("Enter another prime number q (not equal to %d): ", p);
        scanf("%d",&q);
    }while(!isprime(q) || q==p);
    
    //calculate n and set z to (p-1)(q-1)
    n = p*q;
    z = (p-1)*(q-1);
    
    //find e and d
    do{
        printf("Enter an integer e such that 1 < e < %d and gcd(e,%d) = 1: ", z, z);
        scanf("%d",&e);
    }while(e<2 || e>=z || gcd(e,z)!=1);
    
    int k=1;
    while (1) {
        k += z;
        if(k%e==0) {
            d=k/e;
            break;
        }
    }
    
    printf("\nPublic key = (%d,%d)\nPrivate key = (%d,%d)\n", n, e, n, d);
    
    //encrypt and decrypt message
    printf("\nEnter message to encrypt: ");
    scanf("%d",&message);
    
    int c = pow(message,e);
    c = c % n;
    printf("Encrypted message: %d\n", c);
    
    int decrypted = pow(c,d);
    decrypted = decrypted % n;
    printf("Decrypted message: %d\n", decrypted);
    
    return 0;
}