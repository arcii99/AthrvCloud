//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int generatePrimeNumber(int limit);

int main() {

    int p,q,n,e,d,phi;
    int message,encryptedMessage,decryptedMessage;

    srand(time(0));

    p=generatePrimeNumber(100);
    q=generatePrimeNumber(100);

    n=p*q;

    phi=(p-1)*(q-1);

    for(e=2;e<phi;e++)
    {
        if((phi % e)==0) continue;
        int flag=0;
        for(int i=2;i<e;i++)
        {
            if((e % i)==0) flag=1;
        }
        if(flag==0) break;
    }

    for(int i=1;i<=9;i++)
    {
        int x=1+i*phi;
        if(x % e==0)
        {
            d=x/e;
            break;
        }
    }

    printf("Public Key (n,e): (%d,%d)\n",n,e);
    printf("Private Key (n,d): (%d,%d)\n",n,d);

    printf("Enter the message: ");
    scanf("%d",&message);

    encryptedMessage=(int)pow(message,e)%n;
    printf("Encrypted Message: %d\n",encryptedMessage);

    decryptedMessage=(int)pow(encryptedMessage,d)%n;
    printf("Decrypted Message: %d\n",decryptedMessage);

    return 0;
}

int generatePrimeNumber(int limit) {
    int num = rand() % limit + 1;
    int isPrime = 1;
    for (int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if(isPrime == 1 && num != 1) {
        return num;
    }
    else {
        return generatePrimeNumber(limit);
    }
}