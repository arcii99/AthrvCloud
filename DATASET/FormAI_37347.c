//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void print_md5_sum(unsigned char* md) {
    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        printf("Usage: %s [STRING]\n", argv[0]);
        return 1;
    }

    char* plain_text = argv[1];
    size_t plain_text_len = strlen(plain_text);

    unsigned char md5[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)plain_text, plain_text_len, md5);

    printf("MD5 sum of string \"%s\" is: ", plain_text);
    print_md5_sum(md5);

    return 0;
}