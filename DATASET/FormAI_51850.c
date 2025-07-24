//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* cryptohash(char* message)
{
    //Defining required hash variables
    unsigned long h = 5381;
    int c;
    char* hash = malloc(33 * sizeof(char));
    //Looping through the message and converting it into hash
    while (c = *message++)
        h = ((h << 5) + h) + c;
    sprintf(hash, "%lx", h);
    return hash;
}

//Main function to demonstrate the hash function
int main()
{
    char* message = "Hello World!";
    char* hash = cryptohash(message);
    printf("Message: %s \nHash: %s\n", message, hash);
    free(hash);

    return 0;
}