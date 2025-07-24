//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 1000

int gcd(int a, int b) //Helper function to calculate GCD
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int get_public_key(int phi) //Helper function to generate public key
{
    int e;
    for(e=2;e<phi;e++)
    {
        if(gcd(e,phi)==1)
            break;
    }
    return e;
}

int get_private_key(int e, int phi) //Helper function to generate private key
{
    int k=1;
    while(1)
    {
        k += phi;
        if(k%e==0)
            return k/e;
    }
}

void encrypt(int public_key, char* message) //Function to encrypt the message
{
    int i=0;
    while(message[i]!='\0')
    {
        int m = message[i];
        int c = pow(m, public_key);
        printf("%d ", c);
        i++;
    }
    printf("\n");
}

void decrypt(int private_key, int n, int* message, int length) //Function to decrypt the message
{
    int i;
    for(i=0;i<length;i++)
    {
        int m = message[i];
        int c = pow(m, private_key);
        printf("%c", (char)c);
    }
}

int main()
{
    //Generate two random primes p and q
    int p = rand()%MAX+1;
    int q = rand()%MAX+1;
    
    //Calculate n and phi(n)
    int n = p*q;
    int phi = (p-1)*(q-1);
    
    //Generate public and private keys
    int public_key = get_public_key(phi);
    int private_key = get_private_key(public_key, phi);
    
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    
    //Get message from the user
    char message[MAX];
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]%*c", message);
    
    //Encrypt the message
    encrypt(public_key, message);
    
    //Decrypt the message
    int length = strlen(message);
    int encrypted_message[length];
    printf("Enter the encrypted message: ");
    for(int i=0;i<length;i++)
        scanf("%d", &encrypted_message[i]);
    decrypt(private_key, n, encrypted_message, length);
    
    return 0;
}