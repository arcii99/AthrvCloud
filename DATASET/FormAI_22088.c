//FormAI DATASET v1.0 Category: modern Encryption ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 10000

void encryption(char message[], int key)
{
    int i;
    srand(time(0)); //to generate random numbers with every call
    //creating the key as a random string of alphabets
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char randKey[key];
    for(i=0; i<key; i++)
        randKey[i] = alphabet[rand()%26];
    randKey[key] = '\0';
    printf("\n Your Generated Key: %s", randKey);
    
    //encrypting the message based on the key
    printf("\n Encrypted message: ");
    for(i=0; message[i]!='\0'; i++)
    {
        int j = i%key;
        char c = message[i] + randKey[j];
        printf("%c", c);
    }
}

int main()
{
    char message[MAX];
    int key;
    printf("\n Enter the message to be encrypted (Max %d characters): ", MAX);
    gets(message);
    printf("\n Enter the key length: ");
    scanf("%d", &key);
    encryption(message, key);
    return 0;
}