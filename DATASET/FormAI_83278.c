//FormAI DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char message[100];
    int key;
    int i, n;

    // get message from user
    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    // get encryption key from user
    printf("Enter encryption key: ");
    scanf("%d", &key);

    //generate random seed for random number generator
    srand(time(0));

    n = strlen(message);

    //encrypt message using key and random numbers
    for(i=0; i<n; i++)
    {
        message[i] = message[i] + key + rand()%10;
    }

    //display encrypted message
    printf("Encrypted message: %s", message);

    //decrypt message using key and random numbers
    for(i=0; i<n; i++)
    {
        message[i] = message[i] - key - rand()%10;
    }

    //display decrypted message
    printf("Decrypted message: %s", message);

    return 0;
}