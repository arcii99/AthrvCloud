//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void generateHash(char *file_path) {

    FILE *file;
    char data[1024];
    unsigned char hash[MD5_DIGEST_LENGTH];
    int i;

    file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error. Cannot open file.\n");
        return;
    }

    MD5_CTX md5Context;
    MD5_Init(&md5Context);

    while (fread(data, 1, 1024, file)) {
        MD5_Update(&md5Context, data, strlen(data));
    }

    MD5_Final(hash, &md5Context);
    fclose(file);

    printf("Hash value for file '%s':\n", file_path);
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error. Missing file path.\n");
        return 0;
    }

    generateHash(argv[1]);

    return 0;
}