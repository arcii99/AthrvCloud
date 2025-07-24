//FormAI DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret"

void encryptFile(const char* sourcefile, const char* outfile)
{
    FILE* source = fopen(sourcefile, "rb");
    FILE* dest = fopen(outfile, "wb");

    int keyLength = strlen(KEY);
    int index = 0;
    char keychar, temp;

    while (fread(&temp, sizeof(char), 1, source))
    {
        keychar = KEY[index % keyLength];
        temp ^= keychar;

        fwrite(&temp, sizeof(char), 1, dest);

        index++;
    }

    fclose(source);
    fclose(dest);

    printf("Encryption Finished!\n");
}

void decryptFile(const char* sourcefile, const char* outfile)
{
    encryptFile(sourcefile, outfile);
}

int main()
{
    const char* sourceFile = "input.txt";
    const char* encryptedFile = "encrypted.bin";
    const char* decryptedFile = "decrypted.txt";

    encryptFile(sourceFile, encryptedFile);
    decryptFile(encryptedFile, decryptedFile);

    return 0;
}