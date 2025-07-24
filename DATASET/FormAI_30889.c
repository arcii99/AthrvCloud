//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
// Let's start by including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// Now we define our cheerful hash function
void happyHash(unsigned char *in, int inlen, unsigned char *out) {
    // We begin by initializing our MD5 context
    MD5_CTX mdContext;
    MD5_Init(&mdContext);

    // We then update the MD5 context with our input buffer
    MD5_Update(&mdContext, in, inlen);

    // We finalize the MD5 context into our output buffer
    MD5_Final(out, &mdContext);

    // Add a cheerful message to let the user know their data has been hashed
    printf("Yay! Your data has been securely hashed! Congrats!\n");
}

int main() {
    // Let's create some happy input data
    char happyData[100] = "Hello, world! I am a cheerful hash function! :D";

    // Let's allocate some memory for our output buffer
    unsigned char *happyHashOutput = (unsigned char*) malloc(MD5_DIGEST_LENGTH * sizeof(unsigned char));

    // We then call our happyHash function
    happyHash(happyData, strlen(happyData), happyHashOutput);

    // Finally, let's print out our happyHash output in a cheerful way
    printf("Your happy hash is: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", happyHashOutput[i]);
    }
    printf("\nHave a great day! :)");
    
    // Let's free up the memory we allocated for our happyHashOutput buffer
    free(happyHashOutput);

    // We return a happy 0 to signify that our program executed without any errors!
    return 0;
}