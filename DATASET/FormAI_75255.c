//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void md5(char* str, char* result) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str, strlen(str));
    MD5_Final(result, &ctx);
}

void test_md5() {
    char* str = "This is a test string";
    char result[MD5_DIGEST_LENGTH];
    md5(str, result);

    printf("MD5 hash of '%s':\n", str);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");
}

int main() {
    test_md5();

    return 0;
}