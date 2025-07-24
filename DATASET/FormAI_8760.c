//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include<stdio.h>

void main(){
    printf("Hooray! Let's implement Public Key Algorithm!\n\n");
    
    //Step 1: Choose two prime numbers
    int prime1 = 17;
    int prime2 = 23;
    printf("Step 1: We have selected prime numbers %d and %d!\n\n", prime1, prime2);
    
    //Step 2: Calculate n
    int n = prime1 * prime2;
    printf("Step 2: We have calculated n as %d!\n\n", n);
    
    //Step 3: Calculate phi(n)
    int phi = (prime1 - 1) * (prime2 - 1);
    printf("Step 3: We have calculated phi(n) as %d!\n\n", phi);
    
    //Step 4: Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    int e = 5;
    while(e < phi){
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    printf("Step 4: We have selected integer e as %d!\n\n", e);
    
    //Step 5: Calculate d such that e*d ≡ 1 (mod phi(n))
    int d = 1;
    while((d*e)%phi != 1)
        d++;
    printf("Step 5: We have calculated d as %d!\n\n", d);
    
    //Print public and private keys
    printf("Public Key: {%d, %d}\n", e, n);
    printf("Private Key: {%d, %d}\n", d, n);
}

//Function to calculate GCD of two numbers
int gcd(int x, int y){
    while(x != y){
        if(x > y)
            x -= y;
        else
            y -= x;
    }
    return x;
}