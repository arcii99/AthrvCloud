//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Function to check if a number is prime
int isPrime(int num){
  int i;
  for(i=2;i<=sqrt(num);i++){
    if(num%i==0){
      return 0;
    }
  }
  return 1;
}

//Function to find the greatest common divisor of two numbers
int gcd(int a, int b){
  int remainder;
  while(b!=0){
    remainder=a%b;
    a=b;
    b=remainder;
  }
  return a;
}

//Function to perform modular exponentiation
int modular_exponentiation(int base, int exponent, int modulus){
  int result=1;
  while(exponent>0){
    if(exponent%2==1){
      result=(result*base)%modulus;
    }
    base=(base*base)%modulus;
    exponent=exponent/2;
  }
  return result;
}

//Function to generate a random prime number of length 'bits'
int generate_prime(int bits){
  int num=rand()%(int)(pow(2,bits)-pow(2,bits-1))+pow(2,bits-1);
  while(!isPrime(num)){
    num=rand()%(int)(pow(2,bits)-pow(2,bits-1))+pow(2,bits-1);
  }
  return num;
}

int main()
{
    srand(time(NULL));
    int p,q,n,phi,e,d,i,j;
    char message[100];
    printf("Mr. Holmes, we need to encrypt this message. Please provide a message.\n");
    scanf("%[^\n]s", message);
    printf("Excellent. Now please provide a bit size (recommended 512 or 1024 bits).\n");
    scanf("%d", &i);
    printf("Very good. Let us proceed with the implementation of the public-key algorithm.\n");

    //Generate two large prime numbers p and q
    p=generate_prime(i);
    printf("The prime number p is %d\n", p);
    q=generate_prime(i);
    printf("The prime number q is %d\n", q);

    //Calculate n=p*q
    n=p*q;
    printf("The value of n is %d\n", n);

    //Calculate phi=(p-1)*(q-1)
    phi=(p-1)*(q-1);
    printf("The value of phi is %d\n", phi);

    //Choose an integer e such that 1<e<phi and gcd(phi,e) = 1
    e=rand()%phi;
    while(gcd(phi,e)!=1){
      e=rand()%phi;
    }
    printf("The value of e is %d\n", e);

    //Calculate d such that d = e^-1 mod phi
    d=0;
    for(j=1;j<phi;j++){
      if((j*e)%phi==1){
        d=j;
        break;
      }
    }
    printf("The value of d is %d\n", d);

    //Encryption
    int len=strlen(message);
    int encrypted[len];
    printf("\nEncryption Process\n");
    printf("-------------------\n");
    printf("The message to be encrypted is: %s\n", message);
    printf("The value of e is: %d\n", e);
    printf("The value of n is: %d\n", n);
    printf("The cipher text obtained after encryption is: ");
    for(i=0;i<len;i++){
        encrypted[i]=modular_exponentiation(message[i], e, n);
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    //Decryption
    printf("\nDecryption Process\n");
    printf("-------------------\n");
    printf("The value of d is: %d\n", d);
    printf("The value of n is: %d\n", n);
    printf("The decrypted message is: ");
    for(i=0;i<len;i++){
        printf("%c", modular_exponentiation(encrypted[i], d, n));
    }
    printf("\n");
    return 0;
}