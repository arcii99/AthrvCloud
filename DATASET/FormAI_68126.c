//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define KEY 'K' // encryption key

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if(inputFile == NULL) {
        printf("Failed to open input file %s\n", argv[1]);
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if(outputFile == NULL) {
        printf("Failed to open output file %s\n", argv[2]);
        return 1;
    }

    int ch;
    while((ch = getc(inputFile)) != EOF) {
        ch = ch ^ KEY; // do encryption
        putc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File %s encrypted to %s successfully!\n", argv[1], argv[2]);
    return 0;
}