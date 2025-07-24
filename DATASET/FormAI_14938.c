//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encryption key */
#define KEY "Excalibur"

/* Encryption function */
void encrypt_file(FILE* file, char* key) {
    int ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        /* XOR each character with the corresponding character in the key */
        fputc(ch ^ key[i], file);
        i = (i + 1) % strlen(key);
    }
}

int main(int argc, char** argv) {
    /* Check if command line arguments are valid */
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    /* Open the input file */
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open file %s for reading\n", argv[1]);
        return 1;
    }
    /* Open the output file */
    char output_filename[100];
    sprintf(output_filename, "%s_encrypted", argv[1]);
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not create file %s for writing\n", output_filename);
        fclose(input_file);
        return 1;
    }
    /* Encrypt the input file and write to the output file */
    encrypt_file(input_file, KEY);
    printf("File %s encrypted successfully and written to %s\n", argv[1], output_filename);
    /* Close files */
    fclose(input_file);
    fclose(output_file);
    return 0;
}