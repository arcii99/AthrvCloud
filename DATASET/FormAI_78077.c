//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int main(int argc, char **argv) {
    printf("Welcome to the C Antivirus Scanner!\n\n"); 
    char virus[200] = "j7gGhSk9Ll1tRgSv8DpQ";
    char buffer[200];

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size <= strlen(virus)) {
        printf("Warning: File possibly dangerous!\n");
    }

    fread(buffer, file_size, 1, file);
    for (int i = 0; i < file_size - strlen(virus); i++) {
        for (int j = 0; j < strlen(virus); j++) {
            buffer[i+j] ^= virus[j];
        }
    }

    fclose(file);

    if (strstr(buffer, virus)) {
        printf("Alert: Virus detected!\n");
    } else {
        printf("Success: No viruses detected.\n");
    }

    return 0;
}