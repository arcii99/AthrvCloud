//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int m, int n)
{
    /* This function calculates the Greatest Common Divisor of two numbers */
    int r;
    while(n != 0){
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int isPrime(int number)
{
    /* This function checks if a number is prime or not */
    int i;
    for(i=2;i<=sqrt(number);i++){
        if(number%i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i,p,q,n,e,d,phi,msg,cipher,decrypted;
    printf("Enter a prime number: ");
    scanf("%d",&p);
    while(!isPrime(p)){
        printf("%d is not a prime number. Please enter a prime number: ",p);
        scanf("%d",&p);
    }
    printf("Enter another prime number: ");
    scanf("%d",&q);
    while(!isPrime(q)){
        printf("%d is not a prime number. Please enter another prime number: ",q);
        scanf("%d",&q);
    }

    n = p * q;
    phi = (p-1) * (q-1);

    /* Choose an integer e such that e and phi(n) are coprime */
    for(i=2;i<phi;i++){
        if(gcd(i,phi) == 1){
            e = i;
            break;
        }
    }
    /* Find d such that d*e = 1 (mod phi(n)) */
    i = 1;
    while(1){
        if(((i*phi)+1) % e == 0){
            d = ((i*phi)+1) / e;
            break;
        }
        i++;
    }

    printf("Public key: (%d, %d)\n",n,e);
    printf("Private key: (%d, %d)\n",n,d);

    /* Encryption */
    printf("Enter the message you want to encrypt: ");
    scanf("%d",&msg);

    cipher = fmod(pow(msg,e),n);
    printf("Encrypted message: %d\n",cipher);

    /* Decryption */
    decrypted = fmod(pow(cipher,d),n);
    printf("Decrypted message: %d\n",decrypted);

    return 0;
}