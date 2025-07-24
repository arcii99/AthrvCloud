//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main() {
    char input[100];
    char output[MD5_DIGEST_LENGTH+1];
    int i;
    MD5_CTX context;

    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // remove trailing newline
    
    MD5_Init(&context);
    MD5_Update(&context, input, strlen(input));
    MD5_Final(output, &context);

    printf("\nInput string: %s\n", input);
    printf("MD5 hash: ");
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}