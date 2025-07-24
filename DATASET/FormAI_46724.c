//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
// Initializing the seed for the encryption
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int seed = rand(); 

    // Generating the random key 
    int key = seed & 271;

    // Getting the user input
    char msg[100];
    printf("Enter the message to encrypt:");
    scanf("%s", msg);

    // Generating the encrypted message
    for(int i=0; i<strlen(msg); i++)
    {
        msg[i] = ((msg[i] ^ key) | (seed & 127)) & ~(seed << 3); 
    }

    printf("The encrypted message is: %s", msg);

    return 0;
}