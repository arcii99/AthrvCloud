//FormAI DATASET v1.0 Category: Encryption ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int primeCheck(int num){   // helper function to check if a number is prime
    int i;
    for(i=2;i<num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

int gcd(int num1,int num2){   // helper function to find gcd of two numbers
    int temp;
    while(num2){
        temp=num2;
        num2=num1%num2;
        num1=temp;
    }
    return num1;
}

int main(){
    int p,q,n,phi,e,d,i;
    char message[100],ciphertext[100],plaintext[100];
    printf("Enter a prime number p: ");
    scanf("%d",&p);
    while(!primeCheck(p)){    // checking if p is prime or not
        printf("%d is not prime.\nEnter a prime number p: ",p);
        scanf("%d",&p);
    }
    printf("Enter a prime number q: ");
    scanf("%d",&q);
    while(!primeCheck(q)){    // checking if q is prime or not
        printf("%d is not prime.\nEnter a prime number q: ",q);
        scanf("%d",&q);
    }
    n=p*q;   // calculating n
    phi=(p-1)*(q-1);   // calculating phi(n)
    printf("Public Key (n,e): (%d,",n);

    for(e=2;e<phi;e++){   // finding e
        if(gcd(e,phi)==1){
            printf("%d)",e);
            break;
        }
    }
    if(e==phi){   // if e and phi have no common factors
        printf("No Public Key could be generated.");
    }
    printf("\nEnter message to be encrypted: ");
    scanf("%s",message);
    i=0;
    while(message[i]!='\0'){   // encrypting message using public key (n,e)
        plaintext[i]=message[i];
        ciphertext[i]=(int)(pow((int)message[i],e))%n;
        i++;
    }
    ciphertext[i]='\0';
    printf("Encrypted message: ");
    for(i=0;ciphertext[i]!='\0';i++){
        printf("%d",ciphertext[i]);
    }

    // decryption using private key
    for(d=1;d<=phi;d++){   // finding d
        if(((e*d)%phi)==1){
            break;
        }
    }
    printf("\nPrivate Key (n,d): (%d,%d)",n,d);
    i=0;
    while(ciphertext[i]!='\0'){   // decrypting message using private key (n,d)
        plaintext[i]=(int)(pow(ciphertext[i],d))%n;
        i++;
    }
    plaintext[i]='\0';
    printf("\nDecrypted message: %s",plaintext);
    return 0;
}