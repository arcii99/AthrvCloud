//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER 1024

int main(int argc, char** argv)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    size_t bytesRead;

    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((bytesRead = fread(buffer, sizeof(char), MAX_BUFFER, fp)) > 0)
    {
        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}