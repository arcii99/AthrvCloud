//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char* filename = "virus.exe";   // Replace with actual filename
    FILE* fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Check if file is an executable
    char magic_number[2];
    fread(magic_number, sizeof(char), 2, fp);
    if (magic_number[0] != 'M' || magic_number[1] != 'Z') {
        printf("File %s is not an executable\n", filename);
        fclose(fp);
        exit(EXIT_SUCCESS);
    }

    // Check if file is larger than 100 bytes
    fseek(fp, 0L, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    if (filesize <= 100) {
        printf("File %s is too small to be a virus\n", filename);
        fclose(fp);
        exit(EXIT_SUCCESS);
    }
    
    // Check for virus signature
    char virus_sig[] = "int main() { printf(\"I am a virus\")";
    size_t sig_len = strlen(virus_sig);

    char* buffer = malloc(sizeof(char) * sig_len);
    if (buffer == NULL) {
        printf("Could not allocate memory\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(char), sig_len, fp);

    if (strncmp(virus_sig, buffer, sig_len) == 0) {
        printf("File %s is a virus\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }

    fclose(fp);
    free(buffer);

    return 0;
}