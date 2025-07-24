//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char **argv) {
    char file_name[100], key[100];
    FILE *in_file, *out_file;
    int i, encrypt_key;

    if (argc < 4) {
        printf("Usage: %s <input file> <output file> <encryption key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get input file name
    strcpy(file_name, argv[1]);

    // Get output file name
    out_file = fopen(argv[2], "w");

    // Get encryption key
    encrypt_key = atoi(argv[3]);

    // Open input file
    in_file = fopen(file_name, "r");

    if (in_file == NULL) {
        printf("File %s could not be opened!\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Read file contents and encrypt
    while ((i = fgetc(in_file)) != EOF) {
        i = i + encrypt_key;
        fputc(i, out_file);
    }

    // Close input and output files
    fclose(in_file);
    fclose(out_file);

    return 0;
}