//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Touring
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Function to generate random prime number
int random_prime(){
    int p;
    while(1){
        p = rand()%100;
        if(is_prime(p)){
            return p;
        }
    }
}

// Function to generate gcd of two numbers
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

// Function to check if given number is prime or not
int is_prime(int n){
    int i;
    for(i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int p = random_prime();
    int q = random_prime();
    int n = p*q; // Modulus
    int phi = (p-1)*(q-1);
    int e;
    for(e=2; e<phi; e++){
        if(gcd(e,phi) == 1){
            break;
        }
    }
    int d;
    int k = 1;
    while(1){
        k=k+phi;
        if(k%e == 0){
            d=k/e;
            break;
        }
    }

    printf("Public Key : {%d,%d}\n",e,n);
    printf("Private Key : %d\n",d);

    // Encryption
    int m; // Message to be sent
    printf("Enter message : ");
    scanf("%d",&m);
    int c = pow(m,e);
    c = c%n;
    printf("Encrypted message : %d\n",c);

    //Decryption
    int p_msg = pow(c,d);
    p_msg = p_msg%n;
    printf("Decrypted message : %d\n",p_msg);

    return 0;

}