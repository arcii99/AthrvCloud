//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//I'm a metadata extractor that can find all the secrets in your files!

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Yo, I need a file name as an argument!\n");
        return 1;
    }

    char *filename = argv[1];
    printf("Scanning '%s' for juicy metadata...\n", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Oops, I couldn't open that file...\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *file_buffer = malloc(file_size);
    if (file_buffer == NULL) {
        printf("Uh oh, I couldn't allocate a buffer for that file...\n");
        return 1;
    }

    fread(file_buffer, 1, file_size, fp);
    fclose(fp);

    int count = 0;
    char *ptr = file_buffer;
    while ((ptr = strstr(ptr, "secret")) != NULL) {
        count++;
        ptr += strlen("secret");
    }

    printf("I found %d secrets in this file!\n", count);

    free(file_buffer);

    return 0;
}